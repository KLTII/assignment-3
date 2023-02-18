#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) 
{
    /*
     * TODO: homework
     */
    size_t days = 10;
    for (int i = 0; i < days; i++) 
    {
        int num_of_day = i;
        // collect expect and actual fees results
        int base_fee = num_of_day * media->get_late_fee_per_day_in_dollar();
        int fee = (num_of_day >= 5) ? 2 * base_fee : base_fee;

        bool has_mercy = media->get_inventory_id() % 13 == 0 &&
                            ((MovieAction *) media)->action_movie_mercy_rule_apply();
        int expect = has_mercy ? 0 : fee;
        int actual = media->calculate_late_fees(num_of_day);
    }

    return 0;
}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}