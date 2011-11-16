/*
 * Sudokumm 
 * Copyright 2011 Luke Campbell
 *
 * AboutBox.h
 *  Created on: 14 November 2011
 *  Author: Luke campbell
 * 
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ABOUTBOX_H_
#define ABOUTBOX_H_

#include <gtkmm.h>
extern const char *gplv2;
extern const char *sudokumm_xpm[];

class AboutBox : public Gtk::AboutDialog
{

public:
    AboutBox();
    ~AboutBox() {}

};


#endif /* ABOUTBOX_H_ */
