/*
 * MainWindow.h
 *
 *  Created on: Oct 10, 2011
 *      Author: luke
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <gtkmm.h>
#include <stack>

#include "SudokuSquare.h"
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

	Cluster *clusters[27];
	void init_clusters();
	void pushFrame();
	void popFrame();


};


#endif /* MAINWINDOW_H_ */
