/*
 * MainWindow.cc
 *
 *  Created on: Oct 10, 2011
 *      Author: luke
 */
#include <iostream>
#include "MainWindow.h"



MainWindow::MainWindow()
:clear("Cl_ear",true),close("_Close",true)
{

	set_title("Agreement");

	clear.signal_clicked().connect(
			sigc::mem_fun(*this,&MainWindow::onClear));
	close.signal_clicked().connect(
			sigc::mem_fun(*this,&MainWindow::onClose));

	for(int i=0;i<9;i++)
	{
		cols.pack_start(rows[i],true,true,1);
		rows[i].show();
	}
	for(int i=0;i<81;i++)
	{
		square[i] = new SudokuSquare(i);
		rows[i/9].pack_start(*square[i],true,true,1);
		square[i]->set_label(Glib::Ascii::dtostr(i));
		square[i]->signal_button_release_event().connect(
				sigc::bind<SudokuSquare*>(sigc::mem_fun(*this,&MainWindow::handleClick),square[i]));
		square[i]->signal_entry_activate().connect(
				sigc::bind<SudokuSquare*>(sigc::mem_fun(*this,&MainWindow::handleActivate),square[i]));
		square[i]->show();
	}
	buttonRow.pack_start(clear);
	buttonRow.pack_start(close);

	buttonRow.show_all();
	cols.pack_start(buttonRow);


	add(cols);
	cols.show();


	show();
}

MainWindow::~MainWindow()
{
	for(int i=0;i<81;i++)
		delete square[i];
}
gboolean
MainWindow::handleClick(GdkEventButton *event, SudokuSquare *square)
{
	square->showEntry();

	std::cout<<"Square: "<<square->getIndex()<<" was called"<<std::endl;
	return false;
}
void
MainWindow::handleActivate(SudokuSquare *s)
{
	s->set_label(s->getEntry());
	s->showLabel();

}
void
MainWindow::onClear()
{
	for(int i=0;i<81;i++)
	{
		square[i]->set_label(" ");
		square[i]->showLabel();
	}
}
void
MainWindow::onClose()
{
	Gtk::Main::quit();
}