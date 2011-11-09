/*
 * MainWindow.h
 *
 *  Created on: Oct 10, 2011
 *      Author: luke
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <gtkmm.h>
#include "SudokuSquare.h"

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();
protected:
	SudokuSquare *square[81];
	Gtk::VBox cols;
	Gtk::HBox rows[9];
	Gtk::HBox buttonRow;
	Gtk::Button clear;
	Gtk::Button close;
private:
	gboolean handleClick(GdkEventButton*,SudokuSquare*);
	void handleActivate(SudokuSquare *);
	void onClear();
	void onClose();


};


#endif /* MAINWINDOW_H_ */
