#include "bacs/archive/repository.hpp"

#include <boost/thread/locks.hpp>
#include <boost/thread/shared_lock_guard.hpp>

namespace bacs{namespace archive
{
    typedef boost::lock_guard<boost::shared_mutex> lock_guard;
    typedef boost::shared_lock_guard<boost::shared_mutex> shared_lock_guard;

    problem::import_info repository::insert(const problem::id &id, const boost::filesystem::path &location)
    {
        // TODO
    }

    bool repository::extract(const problem::id &id, const boost::filesystem::path &location)
    {
        if (exists(id))
        {
            const shared_lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
                return true;
            }
        }
        return false;
    }

    problem::id_set repository::existing()
    {
        problem::id_set set;
        // TODO
        return set;
    }

    problem::id_set repository::available()
    {
        problem::id_set set;
        // TODO
        return set;
    }

    bool repository::exists(const problem::id &id)
    {
        // FIXME
        return false;
    }

    boost::optional<problem::status_type> repository::status(const problem::id &id)
    {
        if (exists(id))
        {
            const shared_lock_guard lk(m_lock);
            if (exists(id))
            {
                problem::status_type status;
                // TODO
                return status;
            }
        }
        return boost::optional<problem::status_type>();
    }

    bool repository::set_flag(const problem::id &id, const problem::flag_type &flag)
    {
        if (exists(id))
        {
            const lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
                return true;
            }
        }
        return false;
    }

    bool repository::unset_flag(const problem::id &id, const problem::flag_type &flag)
    {
        if (exists(id))
        {
            const lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
                return true;
            }
        }
        return false;
    }

    bool repository::unset_flags(const problem::id &id, const problem::flag_set &flags)
    {
        if (exists(id))
        {
            const lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
            }
        }
        return false;
    }

    bool repository::clear_flags(const problem::id &id)
    {
        if (exists(id))
        {
            const lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
            }
        }
        return false;
    }

    boost::optional<problem::info_type> repository::info(const problem::id &id)
    {
        if (exists(id))
        {
            const shared_lock_guard lk(m_lock);
            if (exists(id))
            {
                problem::info_type info;
                // TODO
                return info;
            }
        }
        return boost::optional<problem::info_type>();
    }

    bool repository::has_flag(const problem::id &id, const problem::flag_type &flag)
    {
        if (exists(id))
        {
            // TODO
        }
        return false;
    }

    boost::optional<problem::hash_type> repository::hash(const problem::id &id)
    {
        if (exists(id))
        {
            const shared_lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
            }
        }
        return boost::optional<problem::hash_type>();
    }

    problem::import_info repository::rename(const problem::id &current, const problem::id &future)
    {
        problem::import_info info;
        // TODO work on error messages
        if (exists(current) && !exists(future))
        {
            const lock_guard lk(m_lock);
            if (exists(current))
            {
                // TODO
            }
        }
        return info;
    }

    problem::import_info repository::repack(const problem::id &id)
    {
        problem::import_info info;
        if (exists(id))
        {
            const lock_guard lk(m_lock);
            if (exists(id))
            {
                // TODO
            }
        }
        return info;
    }
}}