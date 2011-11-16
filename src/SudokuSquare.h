/*
 * Sudokumm 
 * Copyright 2011 Luke Campbell
 *
 * SudokuSquare.h
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

#ifndef SUDOKUSQUARE_H_
#define SUDOKUSQUARE_H_

#include <gtkmm.h>
#include <iostream>
#include "libsudoku/Square.hpp"

typedef void (*SudokuCallback)(void *);

class SudokuSquare : public Gtk::Frame
{
public:
    /**
     * Builds a generic square with an index of 0
     */
	SudokuSquare();
	/**
	 * Builds a square with the index specified
	 * @param index - The index to use to initialize
	 */
	SudokuSquare(guint);
	/**
	 * Doesn't do anything
	 */
	virtual ~SudokuSquare();
	/**
	 * Returns the signal button_release_event from the Event Box
	 */
	Glib::SignalProxy1<bool,GdkEventButton*>
		signal_button_release_event();
	/**
	 * Returns the signal entry_activate from the Entry Box
	 * @return The signal_button_release_event form the Entry Box
	 */
	Glib::SignalProxy0<void> signal_entry_activate();
	/**
	 * Sets the label of the square
	 * @param s - The string to set the label as
	 * @return Always returns true
	 */
	gboolean setLabel(const Glib::ustring &);
	/**
	 * Returns the current index of the square.  You can determine row and
	 * column using row = index/9 and col = index%9
	 * @return The index of the current square
	 */
	guint getIndex();
	/**
	 * Returns The string entered into the Entry Box.
	 * @return The string entered into the Entry Box.
	 */
	Glib::ustring getEntry();
	/**
	 * Hides the label and shows the entry box.
	 */
	void showEntry();
	/**
	 * Hides the entry box and shows the label.
	 */
	void showLabel();
	/**
	 * Registers a callback for the square changed event.
	 * @param callback - The event handler
	 */
	void registerCallback(SudokuCallback);

	Square squareContainer; /// The libsudoku Square

protected:
	guint index;
	Gtk::EventBox eventbox;
	Gtk::Label label;
	Gtk::Entry entry;
	Gtk::HBox overlap;
	/**
	 * The event handler for clicking in the event box
	 */
	gboolean onClick(GdkEventButton *,SudokuSquare *);
	/**
	 * The event handler for activating the entry box
	 */
	void onActivate(SudokuSquare *s);
	/**
	 * The event handler for handling focus out event
	 */
	gboolean onFocusOut(GdkEventFocus *event);
	/**
	 * The event handler for handling the on_enter event
	 */
	gboolean onEnter(GdkEventCrossing *);


private:
	void init();
	SudokuCallback onChange;

};


#endif /* SUDOKUSQUARE_H_ */
