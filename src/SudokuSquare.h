/*
 * SudokuSquare.h
 *
 *  Created on: Oct 11, 2011
 *      Author: luke
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
	SudokuSquare();
	SudokuSquare(guint);
	virtual ~SudokuSquare();
	Glib::SignalProxy1<bool,GdkEventButton*>
		signal_button_release_event();
	Glib::SignalProxy0<void> signal_entry_activate();

	gboolean setLabel(const Glib::ustring &);
	guint getIndex();
	Glib::ustring getEntry();
	void showEntry();
	void showLabel();
	void registerCallback(SudokuCallback);

	Square squareContainer;

protected:
	guint index;
	Gtk::EventBox eventbox;
	Gtk::Label label;
	Gtk::Entry entry;
	Gtk::HBox overlap;
	gboolean onClick(GdkEventButton *,SudokuSquare *);
	void onActivate(SudokuSquare *s);
	gboolean onFocusOut(GdkEventFocus *event);
	gboolean onEnter(GdkEventCrossing *);


private:
	void init();
	SudokuCallback onChange;

};


#endif /* SUDOKUSQUARE_H_ */
