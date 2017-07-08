// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Bibliotheque Lapin

#include		<string.h>
#include		"lapin_private.h"

extern char		*ini_last_error;

#define			PATTERN		"%s -> %p"

t_bunny_ini		*bunny_read_ini(const char		*str)
{
  t_bunny_ini		*ini;

  if ((ini = bunny_read_configuration(BC_INI, str, NULL)) == NULL)
    scream_error_if(return (NULL), bunny_errno, PATTERN, str, ini);
  scream_log_if(PATTERN, str, ini);
  return (ini);
}
