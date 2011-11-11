/*
 * main.cpp
 *
 *  Created on: Oct 9, 2011
 *      Author: luke
 */

#include <gtkmm.h>
#include <iostream>
#include "libsudoku/tools.hpp"
#include "libsudoku/Sudoku.hpp"

#include "MainWindow.h"


int main(int argc, char *argv[])
{
	Gtk::Main kit(argc,argv);
	MainWindow mw;



	Gtk::Main::run(mw);


	return EXIT_SUCCESS;

}
