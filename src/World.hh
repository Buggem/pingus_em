//  $Id: World.hh,v 1.6 2000/03/12 01:43:23 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef WORLD_HH
#define WORLD_HH

#include <ClanLib/core.h>
#include <vector>
#include <iterator>

#include "PinguHolder.hh"
#include "WorldObj.hh"
#include "PLF.hh"
#include "Pingu.hh"
#include "Background.hh"
#include "ColMap.hh"
#include "Entrance.hh"
#include "Exit.hh"
#include "Hotspot.hh"
#include "Liquid.hh"
#include "Trap.hh"
#include "traps/traps.hh"
#include "particles/ParticleHolder.hh"

// World holds all object of the pingu world (pingus, traps, exits,
// entrances, etc.). It keeps control that all objects become time to
// move and can catch each other. 
class World
{
private:
  PinguMap*  map;
  Background* background;

  bool do_armageddon;
  PinguIter armageddon_count;

  unsigned int released_pingus;
  unsigned int allowed_pingus;

  unsigned int number_to_save;

  bool exit_world;
  int  exit_time;  

  vector<WorldObj*> world_obj;
  vector<Entrance*> entrance;
  vector<Exit*>     exits;
  vector<Hotspot*>  hotspot;
  vector<Liquid*>   liquid;
  vector<Trap*>     traps;

  ParticleHolder particle;
  CL_InputSourceProvider* datafile;

  PinguHolder pingus;
  ColMap* colmap;
  PLF*    plf;
public:
  World();
  World(PLF*);
  virtual ~World();

  void    init (PLF*);
  void    init_background (void);
  void    init_worldobjs (void);
  void    init_map (void);
  void    draw_offset (int x, int y, float s=1.0);
  void    let_move (void);
  void    armageddon (void);
  int     get_height (void);
  int     get_width(void);
  bool    is_finished(void);
  int     get_time (void);
  ColMap* get_colmap();
  PLF*    get_plf();
  unsigned int get_released_pingus() { return released_pingus; }
  unsigned int get_allowed_pingus() { return allowed_pingus; }
  unsigned int get_pingus_out() { return pingus.size(); } 
  unsigned int get_saved_pingus() { return pingus.get_saved(); }
  unsigned int get_number_to_save() { return number_to_save; }

  PinguHolder* get_pingu_p(void);
};

#endif

/* EOF */
