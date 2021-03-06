// Copyright 2017-present MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <mongocxx/config/prelude.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace options {

///
/// Class representing the optional arguments to mongocxx::client::start_session.
///
class MONGOCXX_API session {
   public:
    ///
    /// Sets the causal_consistency option.
    ///
    /// If true (the default), each operation in the session will be causally ordered after the
    /// previous read or write operation. Set to false to disable causal consistency.
    ///
    /// Unacknowledged writes are not causally consistent. If you execute a write operation with an
    /// unacknowledged write concern (a mongocxx::write_concern with
    /// mongocxx::write_concern::acknowledge_level of @c k_unacknowledged), the write does not
    /// participate in causal consistency.
    ///
    /// @return
    ///   A reference to the object on which this member function is being called.  This facilitates
    ///   method chaining.
    ///
    /// @see
    /// https://docs.mongodb.com/manual/core/read-isolation-consistency-recency/#causal-consistency
    ///
    session& causal_consistency(bool causal_consistency) noexcept;

    ///
    /// Gets the current value of the causal_consistency option.
    ///
    bool causal_consistency() const noexcept;

    ///
    /// Compare session options for equality.
    ///
    /// @relates session
    ///
    friend MONGOCXX_API bool MONGOCXX_CALL operator==(const session&, const session&);

    ///
    /// Compare session options for inequality.
    ///
    /// @relates session
    ///
    friend MONGOCXX_API bool MONGOCXX_CALL operator!=(const session&, const session&);

   private:
    bool _causal_consistency = true;
};

///
/// Compare session options for equality.
///
/// @relates session
///
MONGOCXX_API bool MONGOCXX_CALL operator==(const session&, const session&);

///
/// Compare session options for inequality.
///
/// @relates session
///
MONGOCXX_API bool MONGOCXX_CALL operator!=(const session&, const session&);

}  // namespace options
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
