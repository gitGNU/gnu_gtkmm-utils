/* -*- Mode: C++; indent-tabs-mode:nil; c-basic-offset:4; -*- */

/*
 *  gtkmm-utils - page-navigator.hh
 *
 *  Copyright (C) 2007 Marko Anastasov
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __GTKMM_UTILS_PAGE_NAVIGATOR_HH__
#define __GTKMM_UTILS_PAGE_NAVIGATOR_HH__

#include <memory>
#include <gtkmm/box.h>

namespace Gtk {

namespace Util {

/**
 * \brief Navigation bar.
 *
 * Used for composing a TileView, otherwise it is completely generic
 * and can be used to display navigation of any kind of page-like view. <p>
 *
 * The widget is composed of a title label, page information label, and
 * buttons which should lead the user to a next or previous page in the view.
 * Use of labels is optional. The title label should describe the information
 * being displayed in a view using this navigation bar. The page information
 * label should inform the user of the current position, ie its value should
 * be dynamically updated to something like 'x - y of z'.
 */
class PageNavigator : public Gtk::HBox
{
public:
    /// \brief Signal emmitted when a next page is requested.
    typedef sigc::signal<void> SignalClickedNext;

    /// \brief Signal emmitted when a previous page is requested.
    typedef sigc::signal<void> SignalClickedPrevious;

    /// \brief Constructs a new PageNavigator.
    explicit PageNavigator();

    /// \brief PageNavigator destructor.
    ~PageNavigator();

    /**
     * \brief Sets a title for the navigation bar.
     *
     * \param title  a string
     */
    void set_title(const Glib::ustring& title);

    /**
     * \brief Sets a custom markup on the title in the bar.
     *
     * \param marked_up_title  escaped markup string; escape strings with
     * Glib::Markup::escape_text()
     */
    void set_title_markup(const Glib::ustring& marked_up_title);

    /**
     * \brief Sets text on a lable which is meant to display page information.
     * This label appears next to the label containing the title.
     * Compose a string such as '11 - 20 of 23' and pass it here.
     *
     * \param info a string to describe current location in a page view
     */
    void set_page_info(const Glib::ustring& info);

    /**
     * \brief Returns a SignalClickedNext, which you can connect to.
     *
     * \return a SignalClickedNext reference
     */
    SignalClickedNext& signal_clicked_next();

    /**
     * \brief Returns a SignalClickedPrevious, which you can connect to.
     *
     * \return a SignalClickedPrevious reference
     */
    SignalClickedPrevious& signal_clicked_previous();
    
protected:
    struct Private;
    std::auto_ptr<Private> priv_;

private:
    // Non-copyable:
    PageNavigator(const PageNavigator& );
    PageNavigator& operator=(const PageNavigator& );
};

} // namespace Util

} // namespace Gtk

#endif // __GTKMM_UTILS_PAGE_NAVIGATOR_HH__
