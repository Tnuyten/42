#include "draw.h"

t_coord	*add_offset(t_coord *co, t_map map)
{
	co->x += map.x_offset;
	co->y += map.y_offset;
	return (co);
}
