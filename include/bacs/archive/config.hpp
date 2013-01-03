#pragma once

#include "bacs/archive/archiver_options.hpp"

#include "bunsan/pm/config.hpp"

#include <boost/filesystem/path.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>

namespace bacs{namespace archive
{
    struct location_config
    {
        template <typename Archive>
        void serialize(Archive &ar, const unsigned int)
        {
            ar & BOOST_SERIALIZATION_NVP(tmpdir);
            ar & BOOST_SERIALIZATION_NVP(repository_root);
        }

        boost::filesystem::path tmpdir;
        boost::filesystem::path repository_root;
    };

    struct problem_config
    {
        template <typename Archive>
        void serialize(Archive &ar, const unsigned int)
        {
            ar & BOOST_SERIALIZATION_NVP(data);
        }

        struct
        {
            template <typename Archive>
            void serialize(Archive &ar, const unsigned int)
            {
                ar & BOOST_SERIALIZATION_NVP(archiver);
                ar & BOOST_SERIALIZATION_NVP(filename);
            }

            archiver_options archiver;
            boost::filesystem::path filename;
        } data;
    };

    struct config
    {
        template <typename Archive>
        void serialize(Archive &ar, const unsigned int)
        {
            ar & BOOST_SERIALIZATION_NVP(lock);
            ar & BOOST_SERIALIZATION_NVP(resolver);
            ar & BOOST_SERIALIZATION_NVP(location);
            ar & BOOST_SERIALIZATION_NVP(problem);
            ar & BOOST_SERIALIZATION_NVP(pm);
        }

        boost::filesystem::path lock;
        boost::property_tree::ptree resolver;

        location_config location;

        problem_config problem;

        bunsan::pm::config pm;
    };
}}
