/*
 * Sudokumm 
 * Copyright 2011 Luke Campbell
 *
 * MainWindow.h
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

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <gtkmm.h>
#include <stack>

#include "SudokuSquare.h"
#include "AboutBox.h"
#include "libsudoku/Cluster.hpp"


/**
 * SudokuFrame - A structure of 81 squares
 */
struct SudokuFrame
{
    Square squares[81];
};
/**
 * MainWindow - The parent window of the application.
 */
class MainWindow : public Gtk::Window
{
public:
	MainWindow();  /// Constructor
	virtual ~MainWindow();   /// Destructor
protected:
	SudokuSquare *square[81]; /// The Sudoku Squares
	Gtk::VBox appVBox;
	Gtk::HBox rows[9];
	Gtk::HBox subcols[27];
	Gtk::VBox subrows[3];
	Gtk::HBox buttonRow;
	Gtk::Button clear;
	Gtk::Button close;
	Gtk::Button back;
	/**
	 * The Action Group for the callbacks and layout of the menus
	 */
	Glib::RefPtr<Gtk::ActionGroup> actionGroup;
	/**
	 * The UI Manager controlling the layout of the menu
	 */
	Glib::RefPtr<Gtk::UIManager> uiManager;

	/**
	 * A stack of frames to be used as a mechanism to allow the user to go
	 * back to a previous game state
	 */
	std::stack<SudokuFrame *> frames;

private:
	/**
	 * The event handler passed to the event boxes to handle the clicked signal
	 */
	gboolean handleClick(GdkEventButton*,SudokuSquare*);
	/**
	 * The event handler passed to the event boxes to handle the clicked signal
	 */
	void handleActivate(SudokuSquare *);
	/**
	 * Clears the squares
	 */
	void onClear();
	/**
	 * Quits the application
	 */
	void onClose();
	/**
	 * Currently not implemented
	 */
	void onBack();
	void buildMenu();
	void build();

	void onSave();
	void onLoad();
	void onAbout();

	Cluster *clusters[27];
	void init_clusters();
	void pushFrame();
	void popFrame();


};


#endif /* MAINWINDOW_H_ */
