//Name: Gia Dao.
//Student ID: 1001747062.
#include <gtkmm.h>
#include <string>
class MainWindow : public Gtk::Window
{
    public:
        MainWindow();
        void on_Cancel_click();
        void on_OK_click(Gtk::Entry*);
        void on_entry_activate(Gtk::Entry*);
};

void MainWindow::on_Cancel_click()
{
    hide();
}

void MainWindow::on_OK_click(Gtk::Entry *entry)
{
    if(entry->get_text() == "Snoopy" || entry->get_text() == "snoopy")
    {
        Gtk::MessageDialog *OKdialog = Gtk::manage(new Gtk::MessageDialog("You guessed <span fgcolor='#0000ff'>correctly</span>!!", true, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, false));
        OKdialog->set_default_response(Gtk::RESPONSE_OK);
        int result = OKdialog->run();
        if (result == Gtk::RESPONSE_OK)
        {
            OKdialog->close();
        }
    }
    else
    {
        Gtk::MessageDialog *OKdialog = Gtk::manage(new Gtk::MessageDialog("Your answer is <span fgcolor='#ff0000'>not correct</span>.", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false));
        OKdialog->set_secondary_text("Please try again", true);
        OKdialog->set_default_response(Gtk::RESPONSE_OK);
        int result = OKdialog->run();
        if (result == Gtk::RESPONSE_OK)
        {
            OKdialog->close();
        }
    }
}

void MainWindow::on_entry_activate(Gtk::Entry *entry)
{
    on_OK_click(entry);
}

MainWindow::MainWindow()
{
    set_title("Welcome to My Guessing Game!");
    set_default_size(600,600);
    Gtk::Box *MainVBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
    add(*MainVBox);
    Gtk::MenuBar *MyMenuBar = Gtk::manage(new Gtk::MenuBar());
    MainVBox->pack_start(*MyMenuBar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *MyFileMenu = Gtk::manage(new Gtk::MenuItem("_Relationship Hints", true));
    MyMenuBar->append(*MyFileMenu);
    Gtk::Menu *MyFileSubMenu = Gtk::manage(new Gtk::Menu());
    MyFileMenu->set_submenu(*MyFileSubMenu);
    Gtk::MenuItem *SubMenuItem_CharlieBrown = Gtk::manage(new Gtk::MenuItem("_Charlie Brown", true));
    MyFileSubMenu->append(*SubMenuItem_CharlieBrown);
    Gtk::MenuItem *SubMenuItem_Woodstock = Gtk::manage(new Gtk::MenuItem("_Woodstock", true));
    MyFileSubMenu->append(*SubMenuItem_Woodstock);
    Gtk::MenuItem *SubMenuItem_Lucy = Gtk::manage(new Gtk::MenuItem("_Lucy", true));
    MyFileSubMenu->append(*SubMenuItem_Lucy);

    Gtk::MenuItem *MyCreatorMenu = Gtk::manage(new Gtk::MenuItem("_Creator Hints", true));
    MyMenuBar->append(*MyCreatorMenu);
    Gtk::Menu *MyCreatorSubMenu = Gtk::manage(new Gtk::Menu());
    MyCreatorMenu->set_submenu(*MyCreatorSubMenu);
    Gtk::MenuItem *SubMenuItem_CharlesSchulz = Gtk::manage(new Gtk::MenuItem("_Charles Schulz", true));
    MyCreatorSubMenu->append(*SubMenuItem_CharlesSchulz);
    Gtk::MenuItem *SubMenuItem_LeeMendelson = Gtk::manage(new Gtk::MenuItem("_Lee Mendelson", true));
    MyCreatorSubMenu->append(*SubMenuItem_LeeMendelson);

    Gtk::MenuItem *MyAnimatedMenu = Gtk::manage(new Gtk::MenuItem("_Animated Specials Hints", true));
    MyMenuBar->append(*MyAnimatedMenu);
    Gtk::Menu *MyAnimatedSubMenu = Gtk::manage(new Gtk::Menu());
    MyAnimatedMenu->set_submenu(*MyAnimatedSubMenu);
    Gtk::MenuItem *SubMenuItem_Peanuts = Gtk::manage(new Gtk::MenuItem("_Peanuts", true));
    MyAnimatedSubMenu->append(*SubMenuItem_Peanuts);

    Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("What is this cartoon character's name?"));
    MainVBox->pack_start(*MyLabel);
    MyLabel->set_justify(Gtk::JUSTIFY_CENTER);

    Gtk::Image *MyImage = Gtk::manage(new Gtk::Image{"Snoopy.png"});
    MainVBox->pack_start(*MyImage);

    Gtk::Box *hBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    MainVBox->add(*hBox);
    Gtk::Entry *entry = Gtk::manage(new Gtk::Entry());
    hBox->add(*entry);
    entry->set_text("Enter your guess here");
    entry->set_max_length(50);
    Gtk::Box *vBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    hBox->pack_start(*vBox);
    Gtk::Button* ok = Gtk::manage(new Gtk::Button("OK"));
    vBox->add(*ok);
    ok->set_border_width(5);
    ok->set_size_request(350,20);
    entry->signal_activate().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainWindow::on_entry_activate),entry));
    ok->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainWindow::on_OK_click),entry));
    Gtk::Button* cancel = Gtk::manage(new Gtk::Button("Cancel"));
    vBox->add(*cancel);
    cancel->set_border_width(5);
    cancel->set_size_request(350,20);
    cancel->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_Cancel_click));

    MainVBox->show_all();
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.MW");
    MainWindow MyWindow;
    app->run(MyWindow);
    return 0;
}
