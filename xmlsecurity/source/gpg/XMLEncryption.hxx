/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_XMLSECURITY_SOURCE_GPG_XMLENCRYPTION_HXX
#define INCLUDED_XMLSECURITY_SOURCE_GPG_XMLENCRYPTION_HXX

#include <sal/config.h>
#include <rtl/ustring.hxx>
#include <cppuhelper/factory.hxx>
#include <cppuhelper/implbase.hxx>
#include <com/sun/star/uno/Exception.hpp>

#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/xml/crypto/XXMLEncryption.hpp>
#include <com/sun/star/xml/crypto/XXMLEncryptionTemplate.hpp>
#include <com/sun/star/xml/crypto/XXMLSecurityContext.hpp>
#include <com/sun/star/xml/crypto/XMLEncryptionException.hpp>

class XMLEncryptionGpg : public cppu::WeakImplHelper< css::xml::crypto::XXMLEncryption,
                                                      css::lang::XServiceInfo >
{
public:
    explicit XMLEncryptionGpg();
    virtual ~XMLEncryptionGpg() override;

    // XXMLEncryption
    virtual css::uno::Reference< css::xml::crypto::XXMLEncryptionTemplate > SAL_CALL encrypt(
        const css::uno::Reference< css::xml::crypto::XXMLEncryptionTemplate >& aTemplate,
        const css::uno::Reference< css::xml::crypto::XSecurityEnvironment >& aEnvironment) override;

    virtual css::uno::Reference< css::xml::crypto::XXMLEncryptionTemplate > SAL_CALL decrypt(
        const css::uno::Reference< css::xml::crypto::XXMLEncryptionTemplate >& aTemplate,
        const css::uno::Reference< css::xml::crypto::XXMLSecurityContext >& aContext) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;

    virtual sal_Bool SAL_CALL supportsService(const OUString& ServiceName) override;

    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;

    // Helper for XServiceInfo
    static css::uno::Sequence< OUString > impl_getSupportedServiceNames();

    static OUString impl_getImplementationName();

    // Helper for registry
    static css::uno::Reference< css::uno::XInterface > SAL_CALL impl_createInstance(
        const css::uno::Reference< css::lang::XMultiServiceFactory >& aServiceManager);

    static css::uno::Reference< css::lang::XSingleServiceFactory > impl_createFactory(
        const css::uno::Reference< css::lang::XMultiServiceFactory >& aServiceManager);
} ;

#endif // INCLUDED_XMLSECURITY_SOURCE_GPG_XMLENCRYPTION_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
