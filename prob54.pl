#!/usr/bin/perl -w
#
#In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
#
#High Card: Highest value card.
#One Pair: Two cards of the same value.
#Two Pairs: Two different pairs.
#Three of a Kind: Three cards of the same value.
#Straight: All cards are consecutive values.
#Flush: All cards of the same suit.
#Full House: Three of a kind and a pair.
#Four of a Kind: Four cards of the same value.
#Straight Flush: All cards are consecutive values of same suit.
#Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
#The cards are valued in the order:
#2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
#
#If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
#
#Consider the following five hands dealt to two players:
#
#Hand	 	Player 1	 	Player 2	 	Winner
#1	 	5H 5C 6S 7S KD
#Pair of Fives
# 	2C 3S 8S 8D TD
#Pair of Eights
# 	Player 2
#2	 	5D 8C 9S JS AC
#Highest card Ace
# 	2C 5C 7D 8S QH
#Highest card Queen
# 	Player 1
#3	 	2D 9C AS AH AC
#Three Aces
# 	3D 6D 7D TD QD
#Flush with Diamonds
# 	Player 2
#4	 	4D 6S 9H QH QC
#Pair of Queens
#Highest card Nine
# 	3D 6D 7H QD QS
#Pair of Queens
#Highest card Seven
# 	Player 1
#5	 	2H 2D 4C 4D 4S
#Full House
#With Three Fours
# 	3C 3D 3S 9S 9D
#Full House
#with Three Threes
# 	Player 1
#The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
#
#How many hands does Player 1 win?

my $p1wins = 0;

open(FILE, "poker.txt") or die "can't open poker.txt";
my @hands=<FILE>;

foreach(@hands)
{
#    print "\n\n" . $_ . "\n";

    my $p1 = substr $_, 0, 15;
    my $p2 = substr $_, 15, 15;

    my $p1rank = handRank($p1);
    my $p2rank = handRank($p2);

    if($p1rank > $p2rank)
    {
	$p1wins = $p1wins + 1;
    }
    
    if($p1rank == $p2rank)
    {
	my $p1card = workingCard($p1, 0);
	my $p2card = workingCard($p2, 0);
	if($p1card > $p2card)
	{
	    $p1wins = $p1wins + 1;
	}
	if($p1card == $p2card)
	{
	    my $p1card2 = workingCard($p1, 1);
	    my $p2card2 = workingCard($p2, 1);	    
	    
	    if($p1card2 > $p2card2)
	    {
		$p1wins = $p1wins + 1;
	    }
	    if($p1card2 == $p2card2)
	    {
		my $p1card3 = workingCard($p1, 2);
		my $p2card3 = workingCard($p2, 2);	    

		if($p1card3 > $p2card3)
		{
		    $p1wins = $p1wins + 1;
		}
		if($p1card3 == $p2card3)
		{
		    my $p1card4 = workingCard($p1, 3);
		    my $p2card4 = workingCard($p2, 3);	    
		    if($p1card4 > $p2card4)
		    {
			$p1wins = $p1wins + 1;
		    }
		}   
	    }
	}
    }
}

close(FILE);

print "ANSWER: $p1wins\n";

sub workingCard
{
    my $hand = shift;
    my $order = shift;

    # check for straight flush
    if(isFlush($hand) && isStraight($hand))
    {
	return straightRank($hand, $order);
    }
    elsif(isFourOfAKind($hand))
    {
	return threeOfAKindRank($hand, $order);
    }
    elsif(isFullHouse($hand))
    {
	return threeOfAKindRank($hand, $order);
    }
    elsif(isFlush($hand))
    {
	return flushRank($hand, $order);
    }
    elsif(isStraight($hand))
    {
	return straightRank($hand, $order);
    }
    elsif(isThreeOfAKind($hand))
    {
	return threeOfAKindRank($hand, $order);
    }
    elsif(isTwoPair($hand))
    {
	return twoPairRank($hand, $order);
    }
    elsif(isPair($hand))
    {
	return pairRank($hand, $order);
    }
    else
    {
	return highCardRank($hand, $order);
    }
}

sub handRank
{
    my $hand = shift(@_);

    # check for straight flush
    if(isFlush($hand) && isStraight($hand))
    {
	return 8;
    }
    elsif(isFourOfAKind($hand))
    {
	return 7;
    }
    elsif(isFullHouse($hand))
    {
	return 6;
    }
    elsif(isFlush($hand))
    {
	return 5;
    }
    elsif(isStraight($hand))
    {
	return 4;
    }
    elsif(isThreeOfAKind($hand))
    {
	return 3;
    }
    elsif(isTwoPair($hand))
    {
	return 2;
    }
    elsif(isPair($hand))
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

sub isFlush
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my $working_suit = 	substr $cards[0], 1;
    foreach(@cards)
    {
	my $suit = substr $_, 1;

	if($suit ne $working_suit)
	{
	    return 0;
	}
	
    }

    return 1;
}

sub isStraight
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if($sorted_numbers[0]+1 == $sorted_numbers[1] &&
       $sorted_numbers[1]+1 == $sorted_numbers[2] &&
       $sorted_numbers[2]+1 == $sorted_numbers[3] &&
       $sorted_numbers[3]+1 == $sorted_numbers[4])
    {
	return 1;
    }
    elsif($sorted_numbers[4] == 14 &&
	  $sorted_numbers[0] == 2 &&
	  $sorted_numbers[1] == 3 &&
	  $sorted_numbers[2] == 4 &&
	  $sorted_numbers[3] == 5)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

sub straightRank
{
    my $hand = shift(@_); my $order = shift(@_);

    die "ERROR straightRank" unless isStraight($hand);
    die "ERROR straightRank order > 0" unless $order == 0;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if($sorted_numbers[4] == 14 &&
	  $sorted_numbers[0] == 2)
    {
	return $sorted_number[3];
    }
    else
    {
	return $sorted_number[4];
    }
}

sub flushRank
{
    my $hand = shift(@_); my $order = shift(@_);

    die "ERROR flushRank" unless isFlush($hand);
    die "ERROR flushRank order > 0" unless $order == 0;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;
    return $sorted_number[4];
}

sub threeOfAKindRank
{
    my $hand = shift(@_); my $order = shift(@_);

    die "ERROR threeOfAKindRank" unless isThreeOfAKind($hand);
    die "ERROR threeOfAKindRank order > 0" unless $order == 0;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    # the middle one will be the correct one
    return $sorted_numbers[2];
}

sub twoPairRank
{
    my $hand = shift(@_); my $order = shift(@_);

    die "ERROR twoPairRank" unless isTwoPair($hand);
    die "ERROR twoPairRank order > 2" unless $order <= 2;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if($order == 0)
    {
	# the second highest card is the playing pair
	return $sorted_numbers[3];
    }
    elsif($order == 1)
    {
	# the second lowest card is the second pair
	return $sorted_numbers[1];	
    }
    else
    {
	if($sorted_numbers[0] != $sorted_numbers[1])
	{
	    return $sorted_numbers[0];
	}
	elsif($sorted_numbers[3] != $sorted_numbers[4])
	{
	    return $sorted_numbers[4];
	}
	else
	{
	    return $sorted_numbers[2];
	}
    }
}

sub pairRank
{
    my $hand = shift(@_); my $order = shift(@_);

    die "ERROR pairRank" unless isPair($hand);
    die "ERROR pairRank order > 3" unless $order <= 3;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;
    
    if($order == 0)
    {
	if($sorted_numbers[0] == $sorted_numbers[1])
	{
	    return $sorted_numbers[0];
	}
	elsif($sorted_numbers[1] == $sorted_numbers[2])
	{
	    return $sorted_numbers[1];
	}
	elsif($sorted_numbers[2] == $sorted_numbers[3])
	{
	    return $sorted_numbers[2];
	}
	elsif($sorted_numbers[3] == $sorted_numbers[4])
	{
	    return $sorted_numbers[3];
	}
    }
    
    my %seen = ();
    foreach(@sorted_numbers)
    {
	$seen{$_}++;
    }

    my @single_cards = ();
    foreach my $key(keys %seen)
    {
	if($seen{$key} == 1)
	{
	    push(@single_cards, $key);
	}
    }

    my @sorted_single_cards = sort{$b <=> $a} @single_cards;
    return $sorted_single_cards[$order-1];
}

sub highCardRank
{
    my $hand = shift;
    my $order = shift;

    die "ERROR pairRank order > 4" unless $order <= 4;

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$b <=> $a} @numbers;
    
    return $sorted_numbers[$order];
}

sub isFullHouse
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if(($sorted_numbers[0] == $sorted_numbers[1] &&
	$sorted_numbers[0] == $sorted_numbers[2] &&
	$sorted_numbers[3] == $sorted_numbers[4]) ||
       ($sorted_numbers[0] == $sorted_numbers[1] &&
	$sorted_numbers[2] == $sorted_numbers[3] &&
	$sorted_numbers[2] == $sorted_numbers[4]))
    {
	return 1;
    } 
    else
    {
	return 0;
    }
}

sub isThreeOfAKind
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if(($sorted_numbers[0] == $sorted_numbers[1] &&
	$sorted_numbers[0] == $sorted_numbers[2]) ||
       ($sorted_numbers[1] == $sorted_numbers[2] &&
	$sorted_numbers[1] == $sorted_numbers[3]) ||
       ($sorted_numbers[2] == $sorted_numbers[3] &&
	$sorted_numbers[2] == $sorted_numbers[4]))
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

sub isTwoPair
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if(($sorted_numbers[0] == $sorted_numbers[1] &&
	$sorted_numbers[2] == $sorted_numbers[3]) ||
       ($sorted_numbers[0] == $sorted_numbers[1] &&
	$sorted_numbers[3] == $sorted_numbers[4]) ||
       ($sorted_numbers[1] == $sorted_numbers[2] &&
	$sorted_numbers[3] == $sorted_numbers[4]))
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

sub isPair
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if($sorted_numbers[0] == $sorted_numbers[1] ||
       $sorted_numbers[1] == $sorted_numbers[2] ||
       $sorted_numbers[2] == $sorted_numbers[3] ||
       $sorted_numbers[3] == $sorted_numbers[4])
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

sub isFourOfAKind
{
    my $hand = shift(@_);

    my @cards = split(' ', $hand);

    my @numbers = ();
    foreach (@cards)
    {
	push(@numbers, cardRank($_));
    }

    my @sorted_numbers = sort {$a <=> $b} @numbers;

    if(($sorted_numbers[0] == $sorted_numbers[1] &&
       $sorted_numbers[0] == $sorted_numbers[2] &&
       $sorted_numbers[0] == $sorted_numbers[3]) || 
       ($sorted_numbers[1] == $sorted_numbers[2] &&
	$sorted_numbers[1] == $sorted_numbers[3] &&
	$sorted_numbers[1] == $sorted_numbers[4]))
    {
	return 1;
    } 
    else
    {
	return 0;
    }
}


sub cardRank
{
    my $card = shift(@_);

    my $rank = substr $card, 0, 1;
    
    if($rank eq 'A')
    {
	$rank = 14;
    }
    elsif($rank eq 'T')
    {
	$rank = 10;
    }
    elsif($rank eq 'J')
    {
	$rank = 11;
    }
    elsif($rank eq 'Q')
    {
	$rank = 12;
    }
    elsif($rank eq 'K')
    {
	$rank = 13;
    }
  
    return $rank;
}
