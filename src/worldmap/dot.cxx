//  $Id: dot.cxx,v 1.7 2003/10/19 12:25:47 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#include <iostream>
#include <assert.h>
#include "../xml_file_reader_old.hxx"
#include "dot.hxx"

namespace Pingus {
namespace WorldMapNS {

Dot::Dot(xmlDocPtr doc, xmlNodePtr cur)
  : Drawable()
{
  assert(cur);

  //std::cout << "Dot::Dot: " << cur->name << std::endl;

  // cur = <dot>...</dot>

  XMLFileReaderOld reader(doc, cur);
  reader.read_vector("position", pos);
  reader.read_string("name", name);

  assert(!name.empty());
}

} // namespace WorldMapNS
} // namespace Pingus

/* EOF */
