/*
 * SudokuSquare.cc
 *
 *  Created on: Oct 11, 2011
 *      Author: luke
 */

#include "SudokuSquare.h"

static bool checkInput(const Glib::ustring&);
static void onChange(void *args);

SudokuSquare::SudokuSquare()
: index(0)
{
	init();
}
SudokuSquare::SudokuSquare(guint index)
: index(index), squareContainer(index/9,index%9)
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
SudokuSquare::setLabel(const Glib::ustring &s)
{
	label.set_markup(s);
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
	eventbox.signal_enter_notify_event().connect(
	        sigc::mem_fun(*this,&SudokuSquare::onEnter));
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
	entry.signal_focus_out_event().connect(
	  sigc::mem_fun(*this,&SudokuSquare::onFocusOut)
	);
	Glib::ustring str = squareContainer.possibilitiesString();
	eventbox.set_tooltip_text(str);

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
#ifdef __DEBUG__
	std::cout<<"Square: "<<square->getIndex()<<" was called"<<std::endl;
#endif
	return false;
}

gboolean
SudokuSquare::onFocusOut(GdkEventFocus *event)
{
	onActivate(this);
	std::cout<<squareContainer<<std::endl;
}


void
SudokuSquare::onActivate(SudokuSquare *square)
{
	if(checkInput(getEntry()))
	{
		Glib::ustring tmp = getEntry();
		tmp.resize(1);
		setLabel(tmp);
		if(!squareContainer.mark(tmp[0]))
		{
			label.set_markup("<span color=\"#FF0000\">" + tmp + "</span>");
		}

	}
	else
		setLabel(" ");
	showLabel();

}

static bool
checkInput(const Glib::ustring &s)
{
	if(s.length()<1)
		return false;
	if(s[0]>='1' && s[0]<='9')
		return true;
	return false;
}


gboolean SudokuSquare::onEnter(GdkEventCrossing *arg)
{
    Glib::ustring str = squareContainer.possibilitiesString();
    eventbox.set_tooltip_text(str);
}

void SudokuSquare::registerCallback(SudokuCallback callback)
{
    onChange = callback;
}
