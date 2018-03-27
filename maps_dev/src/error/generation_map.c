/*
** EPITECH PROJECT, 2018
** generation_map.c
** File description:
**  Description à edit
*/

#include "../../include/my_world_csfml.h"

int world_generating_map(struct_world_windows_t *window,
	 struct_world_info_t *info)
{
	if (info->map_status == 0) {
		free(info->map);
		free(info->map_water);
		info->map = generate_map(info);
		info->map_water = generate_water_map(info);
		info->map_status = 2;
	}
	if (info->map_status == 2) {
		free(info->map_2d);
		free(info->map_water_2d);
		info->map_2d = create_2d_map(info, info->map);
		info->map_water_2d = create_2d_map(info, info->map_water);
		info->map_status = 1;
	}
	draw_2d_map(window, info, info->map_2d, info->map_water_2d);
	return 0;
}

int **generate_map(struct_world_info_t *info)
{
	int **map_3d = malloc(sizeof(int*) * (info->map_size_y + 1));

	for (int i = 0; i < info->map_size_y; i++) {
		map_3d[i] = malloc(sizeof(int) * (info->map_size_x + 1));
		for (int j = 0; j < info->map_size_x; j++)
			map_3d[i][j] = 00;
		map_3d[info->map_size_x] = NULL;
	}
	map_3d[info->map_size_y] = NULL;
	return map_3d;
}

sfVector2f **create_2d_map(struct_world_info_t *info, int **map_3d)
{
	sfVector2f **map_2d = malloc(sizeof(sfVector2f*) * (info->map_size_y
		+ 1));

	for (int i = 0; i < info->map_size_y; i++){
		map_2d[i] = malloc(sizeof(sfVector2f) * (info->map_size_x + 1
		));
		for (int j = 0; j < info->map_size_x; j++) {
			map_2d[i][j] = project_iso_point(info,
				 j * info->scaling_x,
				 i * info->scaling_y,
				  map_3d[i][j] * info->scaling_z);
		}
	}
	map_2d[info->map_size_y] = NULL;
	return map_2d;
}

sfVector2f project_iso_point(struct_world_info_t *info, int x, int y, int z)
{
	int angle_x = 45;
	int angle_y = 15;

	sfVector2f vect;
	vect.x = cos(RADIAN(angle_x)) * x - cos(RADIAN(angle_x)) * y;
	vect.x += info->central_x;
	vect.y = sin(RADIAN(angle_y)) * y + sin(RADIAN(angle_y)) * x - z;
	vect.y += info->central_y;
	return vect;
}

sfConvexShape *world_create_square(sfVector2f x, sfVector2f y,
	 sfVector2f x1, sfVector2f y1)
{
	sfConvexShape *square = sfConvexShape_create();
	sfConvexShape_setPointCount(square, 4);
	sfConvexShape_setPoint(square, 0, x);
	sfConvexShape_setPoint(square, 1, x1);
	sfConvexShape_setPoint(square, 2, y1);
	sfConvexShape_setPoint(square, 3, y);
	sfConvexShape_setOutlineThickness(square, 1);
	sfConvexShape_setFillColor(square, sfGreen);
	sfConvexShape_setOutlineColor(square, sfRed);
	return square;
}
