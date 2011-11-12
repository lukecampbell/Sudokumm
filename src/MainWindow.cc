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
    while (!frames.empty())
    {
        SudokuFrame *frame = frames.top();
        frames.pop();
        delete frame;
    }
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
    actionGroup->add(Gtk::Action::create("GameMenu", "_Game"));

    actionGroup->add(Gtk::Action::create("GameNew", "_New"));

    actionGroup->add(Gtk::Action::create("GameLoad", "_Load"), sigc::mem_fun(
            *this, &MainWindow::onLoad));

    actionGroup->add(Gtk::Action::create("GameSave", "_Save"), sigc::mem_fun(
            *this, &MainWindow::onSave));

    actionGroup->add(Gtk::Action::create("GameQuit", "_Quit"), sigc::mem_fun(
            *this, &MainWindow::onClose));

    /* About Menu */

    actionGroup->add(Gtk::Action::create("AboutMenu", "About"));

    actionGroup->add(Gtk::Action::create("AboutAuthor", "Author"));

    Glib::ustring uiLayout = "<ui>"
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

    try
    {
        uiManager->add_ui_from_string(uiLayout);
    } catch (const Glib::Error &er)
    {
        std::cerr << "Error building menus" << std::endl;
    }

    Gtk::Widget *widget = uiManager->get_widget("/MenuBar");
    if (widget)
        appVBox.pack_start(*widget);
    appVBox.show_all_children();
}

void MainWindow::onSave()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
            Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.add_button(Gtk::Stock::CLOSE, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);
    dialog.set_transient_for(*this);
    ofstream file;
    int result = dialog.run();
    switch (result)
    {
    case Gtk::RESPONSE_OK:
        file.open(dialog.get_filename().c_str(), ofstream::out);
        break;
    case Gtk::RESPONSE_CANCEL:
        return;
        break;
    default:
        return;
    }

    for (int i = 0; i < 81; i++)
    {
        file << square[i]->squareContainer.getValue() << " ";
    }

    file.close();

}

void MainWindow::onLoad()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
            Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.add_button(Gtk::Stock::CLOSE, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
    dialog.set_transient_for(*this);

    ifstream infile;

    int result = dialog.run();

    if (result != Gtk::RESPONSE_OK)
        return;
    cout<<"Loading from file"<<endl;
    infile.open(dialog.get_filename().c_str(), ifstream::in);
    for (int i = 0; i < 81 && !infile.eof(); i++)
    {
        char c;

        infile >> c;

        Glib::ustring str = " ";
        if(square[i]->squareContainer.mark(c))
            str = c;
        square[i]->setLabel(str);

    }

    infile.close();

}

void MainWindow::pushFrame()
{
    SudokuFrame *frame = new SudokuFrame;
    for (int i = 0; i < 81; i++)
    {
        frame->squares[i] = square[i]->squareContainer;
    }
    frames.push(frame);
}
