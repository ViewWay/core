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

#ifndef INCLUDED_VCL_PNGWRITE_HXX
#define INCLUDED_VCL_PNGWRITE_HXX

#include <vcl/dllapi.h>
#include <memory>
#include <vector>

namespace com::sun::star::beans { struct PropertyValue; }
namespace com::sun::star::uno { template <typename > class Sequence; }

class BitmapEx;
class SvStream;

namespace vcl
{
    class PNGWriterImpl;

    class VCL_DLLPUBLIC PNGWriter
    {
        const std::unique_ptr<PNGWriterImpl> mpImpl;

    public:

        explicit PNGWriter(const BitmapEx&, const css::uno::Sequence<css::beans::PropertyValue>* pFilterData = nullptr);
        ~PNGWriter();

        bool Write(SvStream& rStream);

        // additional method to be able to modify all chunk before they are stored
        struct ChunkData
        {
            sal_uInt32                  nType;
            std::vector<sal_uInt8>    aData;
        };
        std::vector<vcl::PNGWriter::ChunkData>& GetChunks();
    };
}

#endif // INCLUDED_VCL_PNGWRITE_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
