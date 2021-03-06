/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_INC_ACCESSIBLEFILTERMENU_HXX
#define INCLUDED_SC_INC_ACCESSIBLEFILTERMENU_HXX

#include "AccessibleContextBase.hxx"
#include <cppuhelper/implbase1.hxx>

#include <com/sun/star/accessibility/XAccessibleSelection.hpp>
#include <com/sun/star/accessibility/XAccessibleText.hpp>
#include <com/sun/star/accessibility/XAccessibleTextAttributes.hpp>
#include <com/sun/star/accessibility/TextSegment.hpp>
#include <vcl/vclptr.hxx>

#include <vector>

namespace com { namespace sun { namespace star {
    namespace accessibility {
        struct AccessibleEventObject;
    }
}}}

class ScMenuFloatingWindow;

typedef ::cppu::ImplHelper1<
        css::accessibility::XAccessibleSelection > ScAccessibleFilterMenu_BASE;

class ScAccessibleFilterMenu :
    public ScAccessibleContextBase,
    public ScAccessibleFilterMenu_BASE
{
public:
    explicit ScAccessibleFilterMenu(
        const css::uno::Reference< css::accessibility::XAccessible>& rxParent,
            ScMenuFloatingWindow* pWin, const OUString& rName, size_t nMenuPos);
    virtual ~ScAccessibleFilterMenu() override;

    virtual bool SAL_CALL isVisible() override;

    /// XAccessibleComponent

    virtual css::uno::Reference< css::accessibility::XAccessible >
        SAL_CALL getAccessibleAtPoint( const css::awt::Point& rPoint ) override;

    virtual void SAL_CALL grabFocus() override;

    virtual sal_Int32 SAL_CALL getForeground() override;

    virtual sal_Int32 SAL_CALL getBackground() override;

    /// XAccessibleContext

    virtual sal_Int32 SAL_CALL getAccessibleChildCount() override;

    virtual css::uno::Reference< css::accessibility::XAccessible> SAL_CALL
        getAccessibleChild(sal_Int32 nIndex) override;

    virtual css::uno::Reference<
        css::accessibility::XAccessibleStateSet> SAL_CALL
        getAccessibleStateSet() override;

    virtual OUString SAL_CALL getImplementationName() override;

    /// XAccessibleEventBroadcaster
    virtual void SAL_CALL
        addAccessibleEventListener(
            const css::uno::Reference< css::accessibility::XAccessibleEventListener>& xListener) override;

    ///  Remove an existing event listener.
    virtual void SAL_CALL
        removeAccessibleEventListener(
            const css::uno::Reference< css::accessibility::XAccessibleEventListener>& xListener) override;

    /// XAccessibleSelection

    virtual void SAL_CALL selectAccessibleChild(sal_Int32 nChildIndex) override;

    virtual sal_Bool SAL_CALL isAccessibleChildSelected(sal_Int32 nChildIndex) override;

    virtual void SAL_CALL clearAccessibleSelection() override;

    virtual void SAL_CALL selectAllAccessibleChildren() override;

    virtual ::sal_Int32 SAL_CALL getSelectedAccessibleChildCount() override;

    virtual css::uno::Reference< css::accessibility::XAccessible > SAL_CALL
        getSelectedAccessibleChild(sal_Int32 nChildIndex) override;

    virtual void SAL_CALL deselectAccessibleChild(sal_Int32 nChildIndex) override;

    /// XInterface

    virtual css::uno::Any SAL_CALL queryInterface(
        css::uno::Type const & rType ) override;

    virtual void SAL_CALL acquire() throw () override;
    virtual void SAL_CALL release() throw () override;

    /// XTypeProvider

    virtual css::uno::Sequence<sal_Int8> SAL_CALL getImplementationId() override;

    /// non-UNO methods

    void appendMenuItem(const OUString& rName, bool bEnabled, size_t nMenuPos);
    void setMenuPos(size_t nMenuPos);
    void setEnabled(bool bEnabled);

protected:

    sal_Int32 getMenuItemCount() const;

    virtual Rectangle GetBoundingBoxOnScreen() const override;

    virtual Rectangle GetBoundingBox() const override;

private:
    bool isSelected() const;

    void updateStates();

private:
    ::std::vector< css::uno::Reference< css::accessibility::XAccessible > > maMenuItems;
    css::uno::Reference< css::accessibility::XAccessibleStateSet >          mxStateSet;

    size_t mnMenuPos;
    VclPtr<ScMenuFloatingWindow> mpWindow;

    bool mbEnabled:1;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
