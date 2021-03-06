#ifndef SPEC_DDS_STREAMS_CORE_POLICY_DETAIL_CORE_POLICY_HPP_
#define SPEC_DDS_STREAMS_CORE_POLICY_DETAIL_CORE_POLICY_HPP_

/*
*                         OpenSplice DDS
*
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
*
*/

/**
 * @file
 */

#include <org/opensplice/streams/core/policy/CorePolicy.hpp>
#include <dds/streams/core/policy/TCorePolicy.hpp>

namespace dds
{
namespace streams
{
namespace core
{
namespace policy
{
typedef dds::streams::core::policy::TStreamFlush<org::opensplice::streams::core::policy::StreamFlush>
StreamFlush;
}
}
}
}

#endif /* SPEC_DDS_STREAMS_CORE_POLICY_DETAIL_CORE_POLICY_HPP_ */
