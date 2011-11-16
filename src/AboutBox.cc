/*
 * Sudokumm 
 * Copyright 2011 Luke Campbell
 *
 * AboutBox.cc
 *
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

#include "AboutBox.h"

AboutBox::AboutBox()
{
    std::vector<Glib::ustring> aauthors;
    Glib::RefPtr<Gdk::Pixbuf> logo;

    aauthors.push_back("Luke Campbell");
    set_version("0.02b");
    set_website("http://www.github.com/lukecampbell/Sudokumm");
    set_authors(aauthors);
    set_website_label("Sudokumm @ github");
    set_copyright("Copyright 2011 Luke Campbell");
    set_license_type(Gtk::LICENSE_LGPL_3_0);
    logo = Gdk::Pixbuf::create_from_xpm_data(sudokumm_xpm);
    set_logo(logo);

}

