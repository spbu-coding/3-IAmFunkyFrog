#include <stdio.h>
#include <math.h>

struct pointf {
    float x1;
    float x2;
};

struct point {
    double x1;
    double x2;
};

struct pointf solve_in_floats(float deltaf) {
    struct pointf answerf;

    answerf.x2 = (deltaf + 2.0001f - 2.0f) / 0.0001f;
    answerf.x1 = 2.0f - answerf.x2;

    return answerf;
}

struct point solve_in_doubles(double delta) {
    struct point answer;

    answer.x2 = (delta + 2.0001 - 2.0) / 0.0001;
    answer.x1 = 2.0 - answer.x2;

    return answer;
}

float find_distancef(struct pointf p1, struct pointf p2) {
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

double find_distance(struct point p1, struct point p2) {
    return sqrt((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

int main() {
    struct pointf answerf = solve_in_floats(0.0f);
    struct point answer = solve_in_doubles(0.0);
    float deltaf = 0.0001f;
    double delta = 0.0001;
    int cnt = 1;

    float distancef;
    double distance;
    do {
        struct pointf delta_answerf = solve_in_floats(deltaf);
        struct point delta_answer = solve_in_doubles(delta);

        distancef = find_distancef(answerf, delta_answerf);
        distance = find_distance(answer, delta_answer);

        printf("\n Experiment: %d \n", cnt);
        printf("Answer in floats x1: %.18f x2: %.18f \n", answerf.x1,  answerf.x2);
        printf("Delta answer in floats x1: %.18f x2: %.18f \n", delta_answerf.x1,  delta_answerf.x2);
        printf("Delta in floats: %.18f Distance in floats: %.16f \n", deltaf, distancef);
        printf("Answer in doubles x1: %.18lf x2: %.18lf \n", answer.x1,  answer.x2);
        printf("Delta answer in doubles x1: %.18lf x2: %.18lf \n", delta_answer.x1,  delta_answer.x2);
        printf("Delta in doubles: %.18lf Distance in doubles: %.16lf \n", delta, distance);

        deltaf /= 2.0f;
        delta /= 2.0;
        cnt++;
    } while (distancef > 0.000001f || distance > 0.000001);

    return 0;
}
