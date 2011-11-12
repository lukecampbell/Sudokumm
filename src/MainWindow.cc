/*
 * MainWindow.cc
 *
 *  Created on: Oct 10, 2011
 *      Author: luke
 */
#include <iostream>
#include "MainWindow.h"

MainWindow::MainWindow() :
    clear("Cl_ear", true), close("_Close", true)
{

    set_title("Sudoku");
    set_position(Gtk::WIN_POS_CENTER);

    buildMenu();

    clear.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onClear));
    close.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onClose));

    for (int i = 0; i < 9; i++)
    {
        appVBox.pack_start(rows[i], true, true, 1);
        rows[i].show();
    }
    for (int i = 0; i < 81; i++)
    {
        square[i] = new SudokuSquare(i);
        rows[i / 9].pack_start(*square[i], true, true, 1);
        square[i]->setLabel(" ");

        square[i]->show();
    }
    buttonRow.pack_start(clear);
    buttonRow.pack_start(close);

    buttonRow.show_all();
    appVBox.pack_start(buttonRow);

    add(appVBox);
    appVBox.show();

    init_clusters();
    show();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 81; i++)
        delete square[i];
}

void MainWindow::onClear()
{
    for (int i = 0; i < 81; i++)
    {
        square[i]->setLabel(" ");
        square[i]->showLabel();
    }
}
void MainWindow::onClose()
{
    Gtk::Main::quit();
}

void MainWindow::init_clusters()
{
    Square *rows[9];
    Square *cols[9];
    Square *boxes[9];
    //rows
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int r = (j / 3) + (3 * (i / 3));
            int c = (j % 3) + (3 * (i % 3));
            rows[j] = &(square[9 * i + j]->squareContainer);
            cols[j] = &(square[9 * j + i]->squareContainer);
            boxes[j] = &(square[9 * r + c]->squareContainer);

        }
        clusters[i] = new Cluster(CLUSTER_ROW, rows);
        clusters[i + 9] = new Cluster(CLUSTER_COL, cols);
        clusters[i + 18] = new Cluster(CLUSTER_BOX, boxes);
    }

    //cols

}

void MainWindow::buildMenu()
{
    actionGroup = Gtk::ActionGroup::create();

    /* Game Menu */
    actionGroup->add(
            Gtk::Action::create("GameMenu","_Game"));

    actionGroup->add(
            Gtk::Action::create("GameNew","_New"));

    actionGroup->add(
            Gtk::Action::create("GameLoad","Load"));

    actionGroup->add(
            Gtk::Action::create("GameSave","Save"));

    actionGroup->add(
            Gtk::Action::create("GameQuit","Quit"),
            sigc::mem_fun(*this,&MainWindow::onClose));

    /* About Menu */

    actionGroup->add(
            Gtk::Action::create("AboutMenu","About"));

    actionGroup->add(
            Gtk::Action::create("AboutAuthor","Author"));




    Glib::ustring uiLayout =
            "<ui>"
            "  <menubar name='MenuBar'>"
            "    <menu action='GameMenu'>"
            "      <menuitem action='GameNew' />"
            "      <menuitem action='GameLoad' />"
            "      <menuitem action='GameSave' />"
            "      <menuitem action='GameQuit' />"
            "    </menu>"
            "    <menu action='AboutMenu'>"
            "      <menuitem action='AboutAuthor' />"
            "    </menu>"
            "  </menubar>"
            "</ui>";

    uiManager = Gtk::UIManager::create();

    uiManager->insert_action_group(actionGroup);


    add_accel_group(uiManager->get_accel_group());

    try {
        uiManager->add_ui_from_string(uiLayout);
    } catch (const Glib::Error &er) {
        std::cerr<<"Error building menus"<<std::endl;
    }

    Gtk::Widget *widget = uiManager->get_widget("/MenuBar");
    if(widget)
        appVBox.pack_start(*widget);
    appVBox.show_all_children();
}
