#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due) 
{
    /*
     * TODO: homework
     */
    for (int i = 0; i < medias.size(); i++) 
    {
        auto& media = medias[i];
        size_t days = 10;
        for (int j = 0; j < days; j++) 
        {
            int num_of_day = j;
            // collect expect and actual fees results
            int fee;
            int late_fee_per_day = media->get_late_fee_per_day_in_dollar();
            if (num_of_day == 0) 
            {
                fee = 0;
            }
            else if (num_of_day <= 5) 
            {
                fee = late_fee_per_day;
            }
            else if (num_of_day <= 10) 
            {
                fee = late_fee_per_day * 2;
            }
            else 
            {
                fee = late_fee_per_day * num_of_day;
            }
        }
    }

    return 0;
}
