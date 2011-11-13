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

struct SudokuFrame
{
    Square squares[81];
};

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
	Gtk::Button back;

	Glib::RefPtr<Gtk::ActionGroup> actionGroup;
	Glib::RefPtr<Gtk::UIManager> uiManager;

	std::stack<SudokuFrame *> frames;

private:
	gboolean handleClick(GdkEventButton*,SudokuSquare*);
	void handleActivate(SudokuSquare *);
	void onClear();
	void onClose();
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
