def play_hangman
  words = File.readlines('./words_alpha.txt')
  index = rand(words.length)
  word = words[index]
  revealed = [false] * (word.length - 1)
  points = 5
  used_chars = []
  until points.zero?
    (0...word.length - 1).each { |index| print(revealed[index] ? word[index] : '_') }
    puts "\nYou have #{points} points left, please enter a char:"
    char = gets.chomp
    # if this char has been previously entered, skip it
    next if used_chars.include?(char)

    used_chars.append(char)
    # decrease points unless char is in word
    points -= 1 unless word.include?(char)
    # update the revealed list
    (0...word.length - 1).each { |index| revealed[index] ||= word[index] == char }
    # if we all chars were revealed
    true if revealed.all?
  end
  false
end

puts play_hangman ? 'You won! Good job!' : 'Loser'
