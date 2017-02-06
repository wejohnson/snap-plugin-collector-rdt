#include <cstdlib>
#include <exception>

#include "rdt.hpp"

namespace rdt {

    Collector::Collector() {
    }

    Collector::~Collector() {
    }

    const Plugin::ConfigPolicy Collector::get_config_policy() {
        return Plugin::ConfigPolicy{};
    }

    std::vector<Plugin::Metric> Collector::get_metric_types(Plugin::Config cfg) {
        std::vector<Plugin::Metric> result;

        result.push_back(Plugin::Metric(
                cmt_capability_ns,
                "bool",
                "This CPU supports LLC Cache Monitoring."
        ));

        return result;
    }

    void Collector::collect_metrics(std::vector<Plugin::Metric> &metrics) {
        metrics.clear();

        Plugin::Metric cmt_capa_metric;
        cmt_capa_metric.set_ns(cmt_capability_ns);
        cmt_capa_metric.set_data(1);
        metrics.push_back(cmt_capa_metric);

        return;
    }

    Plugin::Meta Collector::get_plugin_meta() {
        return Plugin::Meta(Plugin::Collector, this->name, this->version);
    }

}  // namespace rdt

