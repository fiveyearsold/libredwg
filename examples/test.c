/*****************************************************************************/
/*  LibreDWG - Free DWG library                                              */
/*  http://code.google.com/p/libredwg/                                       */
/*                                                                           */
/*    based on LibDWG - Free DWG read-only library                           */
/*    http://sourceforge.net/projects/libdwg                                 */
/*    originally written by Felipe Castro <felipo at users.sourceforge.net>  */
/*                                                                           */
/*  Copyright (C) 2008, 2009 Free Software Foundation, Inc.                  */
/*  Copyright (C) 2009 Felipe Sanches <jucablues@users.sourceforge.net>      */
/*                                                                           */
/*  This library is free software, licensed under the terms of the GNU       */
/*  General Public License as published by the Free Software Foundation,     */
/*  either version 3 of the License, or (at your option) any later version.  */
/*  You should have received a copy of the GNU General Public License        */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*****************************************************************************/

#include <stdio.h>
#include <dwg.h>

int
test_dwg_c(char *filename);

int
main(int argc, char *argv[])
{
  if (argc > 1)
    return (test_dwg_c(argv[1]));
  else
    return (test_dwg_c(NULL));
}

#define FILENAME "example"

int
test_dwg_c(char *filename)
{
  int error;
  Dwg_Data dwg_struct;

  if (filename)
    error = dwg_read_file(filename, &dwg_struct);
  else
    error = dwg_read_file(FILENAME ".dwg", &dwg_struct);

  dwg_free(&dwg_struct);

  if (error)
    {
      printf("\nERROR!\n\n");
    }
  else
    {
      printf("\nSUCCESS!\n\n");
    }

  return error;
}

