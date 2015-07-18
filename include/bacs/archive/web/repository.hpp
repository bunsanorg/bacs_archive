#pragma once

#include <bacs/archive/repository.hpp>
#include <bacs/archive/web/content/form.hpp>

#include <cppcms/application.h>

#include <memory>

namespace bacs {
namespace archive {
namespace web {

class repository : public cppcms::application {
 public:
  repository(cppcms::service &srv,
             const std::shared_ptr<archive::repository> &repository_);

  void main(std::string url) override;

 private:
  template <typename Model, typename Handler, typename Sender>
  void handler_wrapper(const std::string &name, const Handler &handler,
                       const Sender &sender);

  void insert();
  void extract();
  void rename();
  void existing();
  void available();
  void status();
  void with_flag();
  void set_flags();
  void unset_flags();
  void clear_flags();
  void ignore();
  void info();
  void hash();
  void repack();

  template <typename ProtoBuf>
  void send_protobuf(const ProtoBuf &protobuf, const std::string &filename);

  void send_file(const boost::filesystem::path &path,
                 const std::string &filename);

  void send_tempfile(bunsan::tempfile &&tmpfile, const std::string &filename);

 private:
  problem::ImportMap insert_(content::insert &data);
  // void extract_(content::extract &data);
  problem::ImportInfo rename_(content::rename &data);
  problem::IdSet existing_(content::existing &data);
  problem::IdSet available_(content::available &data);
  problem::ImportMap status_(content::status &data);
  problem::IdSet with_flag_(content::with_flag &data);
  problem::IdSet set_flags_(content::set_flags &data);
  problem::IdSet unset_flags_(content::unset_flags &data);
  problem::IdSet clear_flags_(content::clear_flags &data);
  problem::IdSet ignore_(content::ignore &data);
  problem::InfoMap info_(content::info &data);
  problem::HashMap hash_(content::hash &data);
  problem::ImportMap repack_(content::repack &data);

 private:
  const std::shared_ptr<archive::repository> m_repository;
  const boost::filesystem::path m_upload_directory;
};

}  // namespace web
}  // namespace archive
}  // namespace bacs
