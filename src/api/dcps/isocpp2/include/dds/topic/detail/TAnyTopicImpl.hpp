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
#ifndef OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_
#define OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TAnyTopic.hpp>

// Implementation
namespace dds
{
namespace topic
{


template <typename DELEGATE>
TAnyTopic<DELEGATE>::~TAnyTopic()
{
}

template <typename DELEGATE>
dds::topic::qos::TopicQos
TAnyTopic<DELEGATE>::qos() const
{
    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
    return this->delegate()->qos();
}

template <typename DELEGATE>
void
TAnyTopic<DELEGATE>::qos(const dds::topic::qos::TopicQos& qos)
{
    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
    this->delegate()->qos(qos);
}

template <typename DELEGATE>
TAnyTopic<DELEGATE>&
TAnyTopic<DELEGATE>::operator << (const dds::topic::qos::TopicQos& qos)
{
    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
    this->delegate()->qos(qos);
    return *this;
}

template <typename DELEGATE>
const TAnyTopic<DELEGATE>&
TAnyTopic<DELEGATE>::operator >> (dds::topic::qos::TopicQos& qos) const
{
    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
    qos = this->delegate()->qos();
    return *this;
}

template <typename DELEGATE>
dds::core::status::InconsistentTopicStatus
TAnyTopic<DELEGATE>::inconsistent_topic_status() const
{
    ISOCPP_REPORT_STACK_DDS_BEGIN(*this);
    return this->delegate()->inconsistent_topic_status();
}


}
}

// End of implementation

#endif /* OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_ */
