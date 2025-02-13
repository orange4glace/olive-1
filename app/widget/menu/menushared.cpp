/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "menushared.h"

MenuShared olive::menu_shared;

MenuShared::MenuShared()
{
}

void MenuShared::Initialize()
{
  // "New" menu shared items
  new_project_item_ = Menu::CreateItem(this, "newproj", nullptr, nullptr, "Ctrl+N");
  new_sequence_item_ = Menu::CreateItem(this, "newseq", nullptr, nullptr, "Ctrl+Shift+N");
  new_folder_item_ = Menu::CreateItem(this, "newfolder", nullptr, nullptr);

  // "Edit" menu shared items
  edit_cut_item_ = Menu::CreateItem(this, "cut", nullptr, nullptr, "Ctrl+X");
  edit_copy_item_ = Menu::CreateItem(this, "copy", nullptr, nullptr, "Ctrl+C");
  edit_paste_item_ = Menu::CreateItem(this, "paste", nullptr, nullptr, "Ctrl+V");
  edit_paste_insert_item_ = Menu::CreateItem(this, "pasteinsert", nullptr, nullptr, "Ctrl+Shift+V");
  edit_duplicate_item_ = Menu::CreateItem(this, "duplicate", nullptr, nullptr, "Ctrl+D");
  edit_delete_item_ = Menu::CreateItem(this, "delete", nullptr, nullptr, "Del");
  edit_ripple_delete_item_ = Menu::CreateItem(this, "rippledelete", nullptr, nullptr, "Shift+Del");
  edit_split_item_ = Menu::CreateItem(this, "split", nullptr, nullptr, "Ctrl+K");

  // "In/Out" menu shared items
  inout_set_in_item_ = Menu::CreateItem(this, "setinpoint", nullptr, nullptr, "I");
  inout_set_out_item_ = Menu::CreateItem(this, "setoutpoint", nullptr, nullptr, "O");
  inout_reset_in_item_ = Menu::CreateItem(this, "resetin", nullptr, nullptr);
  inout_reset_out_item_ = Menu::CreateItem(this, "resetout", nullptr, nullptr);
  inout_clear_inout_item_ = Menu::CreateItem(this, "clearinout", nullptr, nullptr, "G");

  // "Clip Edit" menu shared items
  clip_add_default_transition_item_ = Menu::CreateItem(this, "deftransition", nullptr, nullptr, "Ctrl+Shift+D");
  clip_link_unlink_item_ = Menu::CreateItem(this, "linkunlink", nullptr, nullptr, "Ctrl+L");
  clip_enable_disable_item_ = Menu::CreateItem(this, "enabledisable", nullptr, nullptr, "Shift+E");
  clip_nest_item_ = Menu::CreateItem(this, "nest", nullptr, nullptr);

  Retranslate();
}

void MenuShared::AddItemsForNewMenu(Menu *m)
{
  m->addAction(new_project_item_);
  m->addSeparator();
  m->addAction(new_sequence_item_);
  m->addAction(new_folder_item_);
}

void MenuShared::AddItemsForEditMenu(Menu *m)
{
  m->addAction(edit_cut_item_);
  m->addAction(edit_copy_item_);
  m->addAction(edit_paste_item_);
  m->addAction(edit_paste_insert_item_);
  m->addAction(edit_duplicate_item_);
  m->addAction(edit_delete_item_);
  m->addAction(edit_ripple_delete_item_);
  m->addAction(edit_split_item_);
}

void MenuShared::AddItemsForInOutMenu(Menu *m)
{
  m->addAction(inout_set_in_item_);
  m->addAction(inout_set_out_item_);
  m->addSeparator();
  m->addAction(inout_reset_in_item_);
  m->addAction(inout_reset_out_item_);
  m->addAction(inout_clear_inout_item_);
}

void MenuShared::AddItemsForClipEditMenu(Menu *m)
{
  m->addAction(clip_add_default_transition_item_);
  m->addAction(clip_link_unlink_item_);
  m->addAction(clip_enable_disable_item_);
  m->addAction(clip_nest_item_);
}

void MenuShared::Retranslate()
{
  // "New" menu shared items
  new_project_item_->setText(tr("&Project"));
  new_sequence_item_->setText(tr("&Sequence"));
  new_folder_item_->setText(tr("&Folder"));

  // "Edit" menu shared items
  edit_cut_item_->setText(tr("Cu&t"));
  edit_copy_item_->setText(tr("Cop&y"));
  edit_paste_item_->setText(tr("&Paste"));
  edit_paste_insert_item_->setText(tr("Paste Insert"));
  edit_duplicate_item_->setText(tr("Duplicate"));
  edit_delete_item_->setText(tr("Delete"));
  edit_ripple_delete_item_->setText(tr("Ripple Delete"));
  edit_split_item_->setText(tr("Split"));

  // "In/Out" menu shared items
  inout_set_in_item_->setText(tr("Set In Point"));
  inout_set_out_item_->setText(tr("Set Out Point"));
  inout_reset_in_item_->setText(tr("Reset In Point"));
  inout_reset_out_item_->setText(tr("Reset Out Point"));
  inout_clear_inout_item_->setText(tr("Clear In/Out Point"));

  // "Clip Edit" menu shared items
  clip_add_default_transition_item_->setText(tr("Add Default Transition"));
  clip_link_unlink_item_->setText(tr("Link/Unlink"));
  clip_enable_disable_item_->setText(tr("Enable/Disable"));
  clip_nest_item_->setText(tr("Nest"));
}
