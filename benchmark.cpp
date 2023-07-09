#include <fstream>
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>
#include "strided_bloom_filter.h"
#include "define.h"


int main() {
    auto *filter = new StridedBloomFilter(1000, HASH_FUNCTION_AMOUNT, 20);

    filter->readBinFileToFilter("../dataset/ag_news_csv/train.bin");
    filter->queryStrided(
            "A bargain hunter's paradise Massachusetts bargain hunters showed up in droves and shopped hard on yesterday's sales tax holiday, buying everything from treadmills and snow blowers to candles and chandeliers, and crediting the 5-percent tax break with bringing them into the stores.\n"
            "3 Researchers seek to untangle the e-mail thread E-mail is a victim of its own success. That's the conclusion of IBM Corp. researchers in Cambridge, who have spent nearly a decade conducting field tests at IBM and other companies about how employees work and use electronic mail. It's clear to them that e-mail has become the Internet's killer application.\n"
            "3 Microsoft Corp. 2.0: a kinder corporate culture Even a genius can mess up. Bill Gates was a brilliant technologist when he cofounded Microsoft , but as he guided it to greatness in both size and historical consequence, he blundered. He terrorized underlings with his temper and parceled out praise like Scrooge gave to charity. Only the lash inspired the necessary aggressiveness to beat the competition, he thought.\n"
            "3 Letters Target the abusers of legal weapons We can all share the outrage, expressed by columnist Steve Bailey (''Summer Sizzler, quot; Aug. 11), at the killings in the city's poor neighborhoods. But there's no need to share his ignorance. He argues for renewal of the so-called assault weapon ban, claiming that otherwise, ''UZIs and AK-47s could again be flooding the streets. quot; His ...\n"
            "3 Somewhere between gleam and gloom President Bush has been saying that the US economy has ''turned the corner. quot; Democratic presidential candidate Senator John F. Kerry, in the wake of this month's poor jobs report, quipped that it was more like a U-turn.\n"
            "3 Technology company sues five ex-employees  A Marlborough-based technology company is suing five former employees, including three senior managers, for allegedly conspiring against their employer while working on opening a competing business.\n"
            "3 Grant to aid Lynn Central Square Central Square in Lynn should be looking a bit brighter. New sidewalks, curbs, fences, lights, landscaping, and road improvements are planned for the Gateway Artisan Block, a key area of the square, with \\$830,000 in state grant money given to Lynn last week.\n"
            "3 State grant to aid Lynn; Bank gives Salem \\$10k Central Square in Lynn should be looking a bit brighter. New sidewalks, curbs, fences, lights, landscaping, and road improvements are planned for the Gateway Artisan Block, a key area of the square, with \\$830,000 in state grant money given to Lynn last week.\n"
            "3 A New Legal Chapter for a 90's Flameout A lawsuit against Gary Winnick, the former chief of Global Crossing, refocuses attention on what Mr. Winnick knew about his company's finances as it imploded.\n"
            "3 Will Russia, the Oil Superpower, Flex Its Muscles? Russia is again emerging as a superpower - but the reason has less to do with nuclear weapons than with oil.",
            5);

    auto longest_chain = filter->getLongestChain();
    for (size_t i = 0; i < longest_chain.size(); i++) {
        spdlog::info("longest chain {}: {}", i, longest_chain[i]);
    }

    filter->clear();
    return 0;
}
