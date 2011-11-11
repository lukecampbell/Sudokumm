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
		square[i]->setLabel(" ");

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


void
MainWindow::onClear()
{
	for(int i=0;i<81;i++)
	{
		square[i]->setLabel(" ");
		square[i]->showLabel();
	}
}
void
MainWindow::onClose()
{
	Gtk::Main::quit();
}

void
MainWindow::init_clusters()
{
	Square *rows[9];
	Square *cols[9];
	Square *boxes[9];
	//rows
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			int r = (j/3) + (3 * (i/3));
			int c = (j%3) + (3 * (i%3));
			rows[j] = &(square[9*i + j]->squareContainer);
			cols[j] = &(square[9*j + i]->squareContainer);
			boxes[j] = &(square[9* r + c]->squareContainer);

		}
		clusters[i] = new Cluster(CLUSTER_ROW,rows);
		clusters[i+9] = new Cluster(CLUSTER_COL,cols);
		clusters[i+18] = new Cluster(CLUSTER_BOX,boxes);
	}

	//cols

}
