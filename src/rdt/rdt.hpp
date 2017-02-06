#ifndef SNAP_PLUGIN_COLLECTOR_RDT_RDT_HPP
#define SNAP_PLUGIN_COLLECTOR_RDT_RDT_HPP

#include <vector>

#include "snap/plugin.h"
#include "snap/config.h"
#include "snap/metric.h"

namespace rdt {

    class Collector : public Plugin::CollectorInterface {
    public:
        Collector();
        ~Collector();

        const Plugin::ConfigPolicy get_config_policy();
        std::vector<Plugin::Metric> get_metric_types(Plugin::Config cfg);
        void collect_metrics(std::vector<Plugin::Metric> &metrics);
        Plugin::Meta get_plugin_meta();

        std::string name = "rdt";
        int version = 1;

    private:
        Collector(const Collector &that) {};

        const std::vector<Plugin::Metric::NamespaceElement> cmt_capability_ns = {{"intel"}, {"rdt"}, {"capabilities"}, {"cmt_capability"}};
    };

}  // namespace rdt

#endif //SNAP_PLUGIN_COLLECTOR_RDT_RDT_HPP
