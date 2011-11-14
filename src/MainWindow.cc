/*
 * MainWindow.cc
 *
 *  Created on: Oct 10, 2011
 *      Author: luke
 */
#include <iostream>
#include "MainWindow.h"

/**
 * MainWindow()
 * Builds the basic graphical interface
 */
MainWindow::MainWindow() :
    clear("Cl_ear", true), close("_Close", true), back("_Back", true)
{
    build();
}
/**
 * ~MainWindow()
 * Deletes all the squares and pops all the frames in the stack
 */
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

/**
 * build()
 * Builds the GUI and links the callbacks and signal handlers
 */
void MainWindow::build()
{

    set_title("Sudoku");
    set_position(Gtk::WIN_POS_CENTER);

    buildMenu();

    clear.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onClear));
    close.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onClose));
    back.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onBack));
    for (int i = 0; i < 3; i++)
    {
        appVBox.pack_start(subrows[i], true, true, 2);
        subrows[i].show();
    }
    for (int i = 0; i < 9; i++)
    {
        subrows[i / 3].pack_start(rows[i], true, true, 1);
        rows[i].show();
    }
    for (int i = 0; i < 27; i++)
    {
        rows[i / 3].pack_start(subcols[i], true, true, 2);
        subcols[i].show();
    }
    for (int i = 0; i < 81; i++)
    {
        square[i] = new SudokuSquare(i);
        subcols[i / 3].pack_start(*square[i], true, true, 1);
        square[i]->setLabel(" ");

        square[i]->show();
    }
//    buttonRow.pack_start(back);
    buttonRow.pack_start(clear);
    buttonRow.pack_start(close);

    buttonRow.show_all();
    appVBox.pack_start(buttonRow);

    add(appVBox);
    appVBox.show();

    init_clusters();
    show();

}
/**
 * onClear()
 * Clears all squares in the application.  Sets each label to blank/space,
 * and forces each square to show a label
 */
void MainWindow::onClear()
{
    for (int i = 0; i < 81; i++)
    {
        square[i]->squareContainer.mark('-');
        square[i]->setLabel(" ");
        square[i]->showLabel();
    }
}
/**
 * onClose()
 * Quits the application
 */
void MainWindow::onClose()
{
    Gtk::Main::quit();
}
/**
 * onBack()
 * Yet to implemented.  Evenetually it will allow the user to go back
 */
void MainWindow::onBack()
{

}
/**
 * init_clusters()
 * Initializes all the clusters for each square, and links the squares to them.
 */
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
/**
 * buildMenu()
 * Builds the menu for the GUI, I still need to implement the authors dialog
 */
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
/**
 * onSave()
 * Presents a Save File dialog to the user to save the current game state
 */
void MainWindow::onSave()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
            Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.add_button(Gtk::Stock::CLOSE, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);
    dialog.set_transient_for(*this);

    Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
    filter->set_name("Sudoku Save File");
    filter->add_pattern("*.sud");
    dialog.add_filter(filter);

    filter = Gtk::FileFilter::create();
    filter->set_name("All Files");
    filter->add_pattern("*");
    dialog.add_filter(filter);

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
/**
 * onLoad()
 * Presents a dialog to load a file to load the state of the application
 */
void MainWindow::onLoad()
{
    Gtk::FileChooserDialog dialog("Please choose a file",
            Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.add_button(Gtk::Stock::CLOSE, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
    dialog.set_transient_for(*this);

    Glib::RefPtr<Gtk::FileFilter> filter = Gtk::FileFilter::create();
    filter->set_name("Sudoku Save File");
    filter->add_pattern("*.sud");
    dialog.add_filter(filter);

    filter = Gtk::FileFilter::create();
    filter->set_name("All Files");
    filter->add_pattern("*");
    dialog.add_filter(filter);

    ifstream infile;

    int result = dialog.run();

    if (result != Gtk::RESPONSE_OK)
        return;
#ifdef __DEBUG__
    cout << "Loading from file" << endl;
#endif
    infile.open(dialog.get_filename().c_str(), ifstream::in);
    if(infile.fail())
        return;
    onClear();
    for (int i = 0; i < 81 && !infile.eof(); i++)
    {
        char c;

        infile >> c;

        Glib::ustring str = " ";

        if (square[i]->squareContainer.mark(c))
            str = c;

        // If the character is legal but inappropriate for the square
        // set it anyway and color it red.
        else if(c>='1' && c<='9')
        {
            str = "<span color=\"#FF0000\">";
            str += c;
            str += "</span>";
        }
        // Handle illegal chars
        else
        {
            str = " ";
        }
        // blanks are legal so we need to mark them as empty squares in the gui
        if (c == '0' || c=='-' )
            str = " ";
        square[i]->setLabel(str);

    }

    infile.close();

}
/**
 * pushFrame()
 * Pushes the current state onto the Frame stack.  To be used as a mechanism
 * to go back
 */
void MainWindow::pushFrame()
{
    SudokuFrame *frame = new SudokuFrame;
    for (int i = 0; i < 81; i++)
    {
        frame->squares[i] = square[i]->squareContainer;
    }
    frames.push(frame);
}
