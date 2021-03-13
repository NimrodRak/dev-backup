def array_diff(a, b)
  a.collect { |x| x unless b.include?(x)}.compact
end

def spinWords(string)
  string.split.collect { |word| word.length >= 5 ? word.reverse : word }.join(' ')
end

def gravity_flip(direction, array)
  old = array
  top = old.max
  rows = []
  until top.zero?
    count = 0
    array.each_with_index do |x, i|
      if x == top
        array[i] -= 1
        count += 1
      end
    end
    top = old.max
    rows.append(count)
  end
  new_list = [0] * rows.max
  rows.each do |row|
    (0...row).each do |i|
      new_list[(direction == 'L' ? i : new_list.length - 1 - i)] += 1
    end
  end
  new_list
end
print gravity_flip("L", [1, 4, 5, 3, 5])