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
#ifndef OSPL_DDS_TOPIC_DETAIL_TOPIC_HPP_
#define OSPL_DDS_TOPIC_DETAIL_TOPIC_HPP_

/**
 * @file
 */

// Implementation

#include <dds/core/ref_traits.hpp>
#include <dds/topic/TopicTraits.hpp>
#include <dds/core/status/Status.hpp>
#include <dds/core/status/State.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <dds/topic/AnyTopic.hpp>

#include <org/opensplice/core/config.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/topic/AnyTopicDelegate.hpp>
#include <org/opensplice/topic/TopicDescriptionDelegate.hpp>

#include "u_topic.h"

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds
{
namespace topic
{
template <typename T>
class TopicListener;

}
}

namespace dds
{
namespace topic
{
namespace detail
{
template <typename T>
class Topic;
}
}
}



/***************************************************************************
 *
 * dds/topic/detail/Topic<> DELEGATE declaration.
 * Implementation can be found in dds/topic/detail/TTopicImpl.hpp
 *
 ***************************************************************************/
template <typename T>
class dds::topic::detail::Topic : public org::opensplice::topic::AnyTopicDelegate
{
public:

    typedef typename ::dds::core::smart_ptr_traits< Topic<T> >::ref_type ref_type;
    typedef typename ::dds::core::smart_ptr_traits< Topic<T> >::weak_ref_type weak_ref_type;

    Topic(const dds::domain::DomainParticipant& dp,
          const std::string& name,
          const std::string& type_name,
          const dds::topic::qos::TopicQos& qos,
          dds::topic::TopicListener<T>* listener,
          const dds::core::status::StatusMask& mask);

    Topic(const dds::domain::DomainParticipant& dp,
          const std::string& name,
          const std::string& type_name,
          const dds::topic::qos::TopicQos& qos,
          u_topic uTopic);

    virtual ~Topic();

    virtual void close();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    dds::topic::Topic<T, dds::topic::detail::Topic> wrapper();


public:

    void listener(dds::topic::TopicListener<T>* listener,
                  const ::dds::core::status::StatusMask& mask);

    dds::topic::TopicListener<T>* listener();

    virtual void listener_notify(ObjectDelegate::ref_type source,
                                 uint32_t       triggerMask,
                                 void           *eventData,
                                 void           *listener);

    dds::topic::TTopicDescription<TopicDescriptionDelegate> clone();

    static dds::topic::Topic<T, dds::topic::detail::Topic>
    discover_topic(const dds::domain::DomainParticipant& dp,
                   const std::string& name,
                   const dds::core::Duration& timeout);

    static void
    discover_topics(const dds::domain::DomainParticipant& dp,
                    std::vector<dds::topic::Topic<T, dds::topic::detail::Topic> >& topics,
                    uint32_t max_size);

};

/** @endcond */

// End of implementation

#endif /* OSPL_DDS_TOPIC_DETAIL_TOPIC_HPP_ */
