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

class SudokuSquare : public Gtk::Frame
{
public:
	SudokuSquare();
	SudokuSquare(guint);
	virtual ~SudokuSquare();
	Glib::SignalProxy1<bool,GdkEventButton*>
		signal_button_release_event();
	Glib::SignalProxy0<void> signal_entry_activate();
	gboolean set_label(const Glib::ustring &);
	guint getIndex();
	Glib::ustring getEntry();
	void showEntry();
	void showLabel();

protected:
	guint index;
	Gtk::EventBox eventbox;
	Gtk::Label label;
	Gtk::Entry entry;
	Gtk::HBox overlap;
	gboolean onClick(GdkEventButton *,SudokuSquare *);
	void onActivate(SudokuSquare *s);

private:
	void init();

};


#endif /* SUDOKUSQUARE_H_ */
