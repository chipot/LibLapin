// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2016
//
// Lapin library

#include		<sstream>
#include		"lapin_private.h"

#define			PATTERN		"%p conf, %zu index -> %p"

t_bunny_configuration	*bunny_configuration_get_case(t_bunny_configuration	*conf,
						      size_t			n)
{
  SmallConf		*c = (SmallConf*)conf;
  t_bunny_configuration	*cnf = NULL;

  try
    {
      if ((cnf = (t_bunny_configuration*)&(*c)[n]) == NULL)
	scream_error_if(return (cnf), bunny_errno, PATTERN, conf, n, cnf);
      scream_log_if(PATTERN, conf, n, cnf);
      return (cnf);
    }
  catch (...)
    {}
  scream_error_if(return (cnf), bunny_errno, PATTERN, conf, n, cnf);
  return (NULL);
}

