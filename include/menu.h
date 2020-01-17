/**
 * Copyright (c) 2019 WineGUI
 *
 * \file    menu.h
 * \brief   The main-menu
 * \author  Melroy van den Berg <webmaster1989@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <gtkmm.h>

/**
 * \class Menu
 * \brief The top main-menu
 */
class Menu: public Gtk::MenuBar
{
public:
  sigc::signal<void> signal_preferences; /*!< on preferences button clicked signal */
  sigc::signal<void> signal_quit; /*!< on quite button clicked signal */
  sigc::signal<void> signal_refresh; /*!< on refresh button clicked signal */
  sigc::signal<void> signal_new_machine; /*!< on new button clicked signal */
  sigc::signal<void> signal_run; /*!< on new new button clicked signal */
  sigc::signal<void> signal_edit_machine; /*!< on edit button clicked signal */
  sigc::signal<void> signal_settings_machine; /*!< on settings button clicked signal */
  sigc::signal<void> signal_remove_machine; /*!< on remove button clicked signal */
  sigc::signal<void> signal_show_about; /*!< on about button clicked signal */

  Menu();
  virtual ~Menu();
  Gtk::Menu* GetMachineMenu();

protected:
  // Child widgets
  Gtk::MenuItem file; /*!< File menu button */
  Gtk::MenuItem view; /*!< View menu button */
  Gtk::MenuItem machine; /*!< Machine menu button */
  Gtk::MenuItem help; /*!< Help menu button */
  Gtk::Menu file_submenu; /*!< File sub menu */
  Gtk::Menu view_submenu; /*!< View sub menu */
  Gtk::Menu machine_submenu; /*!< Machine sub menu */
  Gtk::Menu help_submenu; /*!< Help sub menu */
  Gtk::SeparatorMenuItem separator1; /*!< Seperator */
  Gtk::SeparatorMenuItem separator2; /*!< Seperator */

private:
  Gtk::MenuItem* CreateImageMenuItem(const Glib::ustring& label_text, const Glib::ustring& icon_name);
};
