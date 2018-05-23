<?php
$functions = [
  20 => [
    "bunny_circle_collision_dot",
    "bunny_circle_collision",
    "bunny_rectangular_collision_dot",
    "bunny_rectangular_collision",
    "bunny_clip_collision_dot",
    "bunny_clip_collision",
    "bunny_triangle_collision_dot",
    "bunny_quad_collision_dot",
  ],
  30 => [
    "bunny_collision_equation_dot",
  ],
  40 => [
    "t_bunny_collision_type",
    "t_bunny_collision",
    "t_bunny_dot_collision",
    "t_bunny_circle_collision",
    "t_bunny_line_collision",
    "t_bunny_triangle_collision",
    "t_bunny_rectangular_collision",
    "t_bunny_quad_collision",
    "t_bunny_equation_collision",
    "t_bunny_collide_point",
    "bunny_collide",
    "bunny_draw_collision_shape",
  ],
];
foreach ($functions as $f => $l)
{
  foreach ($l as $k)
  {
    $circle_level[$k] = $f;
  }
}
