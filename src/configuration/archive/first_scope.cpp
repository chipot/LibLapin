// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2015
//
// Bibliothèque Lapin

#include		"lapin_private.h"

t_bunny_ini_scope	*bunny_ini_first_scope(t_bunny_ini		*in)
{
  t_bunny_ini_scope	*ini;

  ini = bunny_configuration_first((t_bunny_configuration*)in);
  scream_log_if("%p -> %p", in, ini);
  return (ini);
}

