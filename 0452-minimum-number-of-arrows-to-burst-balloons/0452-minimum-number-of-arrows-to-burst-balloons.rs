impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
    /**
         When balloons are sorted by their end positions, shooting an arrow at the end position of the first balloon ensures that any other balloon whose start position is before or at this end position will be covered by this shot. This maximizes the number of balloons that can be burst with a single arrow.
        **/
        let mut points = points.clone();
        points.sort_by(|a, b| a[1].cmp(&b[1]));

        let mut res = 1; // Starting with one arrow as we're guaranteed to have at least one balloon.
        let mut prev_end = points[0][1]; // The end position of the first balloon after sorting.

        for point in points.iter() {
            let curr_start = point[0];
            let curr_end = point[1];
            
            // If the current balloon starts after the previous one ends, an additional arrow is required.
            if curr_start > prev_end {
                res += 1;
                prev_end = curr_end;
            }
        }
        res   
    }
}