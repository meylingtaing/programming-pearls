#!/usr/bin/perl

# Outputs a list of unique, random numbers

use warnings;
use strict;

my $num_nums = 1000000;
my $max_num  = 10000000;

my %used;

for (1..$num_nums) {
    my $n;
    do { $n = int(rand($max_num)) } while $used{$n};
    $used{$n}++;
    print "$n\n";
}
