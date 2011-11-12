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
#include "libsudoku/Cluster.hpp"

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	virtual ~MainWindow();
protected:
	SudokuSquare *square[81];
	Gtk::VBox appVBox;
	Gtk::HBox rows[9];
	Gtk::HBox buttonRow;
	Gtk::Button clear;
	Gtk::Button close;

	Glib::RefPtr<Gtk::ActionGroup> actionGroup;
	Glib::RefPtr<Gtk::UIManager> uiManager;



private:
	gboolean handleClick(GdkEventButton*,SudokuSquare*);
	void handleActivate(SudokuSquare *);
	void onClear();
	void onClose();
	void buildMenu();
	Cluster *clusters[27];
	void init_clusters();


};


#endif /* MAINWINDOW_H_ */
