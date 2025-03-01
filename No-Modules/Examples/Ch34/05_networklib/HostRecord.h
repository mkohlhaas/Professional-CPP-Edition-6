#pragma once

#include "networklib.h"
#include <memory>
#include <string>

// A class wrapping a HostHandle from the networklib library.
class HostRecord final
{
  public:
    // Looks up the host record for the given host.
    explicit HostRecord(const std::string &host) : m_hostHandle{lookupHostByName(host.c_str()), freeHostHandle}
    {
    }

    // Returns the underlying handle.
    HostHandle *get() const noexcept
    {
        return m_hostHandle.get();
    }

  private:
    std::unique_ptr<HostHandle, decltype(&freeHostHandle)> m_hostHandle;
};
