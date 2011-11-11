/*
 * SudokuSquare.cc
 *
 *  Created on: Oct 11, 2011
 *      Author: luke
 */

#include "SudokuSquare.h"

SudokuSquare::SudokuSquare()
: index(0)
{
	init();
}

SudokuSquare::SudokuSquare(guint index)
: index(index)
{
	init();
}


SudokuSquare::~SudokuSquare()
{

}

Glib::SignalProxy1<bool,GdkEventButton*>
SudokuSquare::signal_button_release_event()
{
	return eventbox.signal_button_release_event();
}

Glib::SignalProxy0<void>
SudokuSquare::signal_entry_activate()
{
	return entry.signal_activate();
}

gboolean
SudokuSquare::set_label(const Glib::ustring &s)
{
	label.set_label(s);
	return true;
}
guint
SudokuSquare::getIndex()
{
	return index;
}

void
SudokuSquare::init()
{
	set_size_request(50,50);
	add(eventbox);
	overlap.pack_start(label,true,true,0);
	overlap.pack_start(entry,true,true,0);
	eventbox.add(overlap);
	entry.set_width_chars(1);

	label.show();
	entry.hide();
	overlap.show();
	eventbox.set_events(Gdk::BUTTON_RELEASE_MASK | Gdk::KEY_PRESS_MASK);


	eventbox.show();
	signal_button_release_event().connect(
	  sigc::bind<SudokuSquare*>(
	    sigc::mem_fun(*this,&SudokuSquare::onClick),
		this)
	);
	signal_entry_activate().connect(
	  sigc::bind<SudokuSquare*>(
	    sigc::mem_fun(*this,&SudokuSquare::onActivate),
	    this)
	  );

}

Glib::ustring
SudokuSquare::getEntry()
{
	return entry.get_text();
}
void
SudokuSquare::showEntry()
{
	label.hide();
	entry.show();
	entry.grab_focus();
}
void
SudokuSquare::showLabel()
{
	entry.hide();
	label.show();
}

gboolean
SudokuSquare::onClick(GdkEventButton *event, SudokuSquare *square)
{
   square->showEntry();
	std::cout<<"Square: "<<square->getIndex()<<" was called"<<std::endl;
   return false;
}
void
SudokuSquare::onActivate(SudokuSquare *square)
{
	square->set_label(square->getEntry());
	square->showLabel();
}
