import argparse

def transform_name(name):
    parts = name.split(". ", 1)

    if len(parts) != 2:
        raise ValueError("Name is not in the correct format")

    number, rest = parts
    rest = rest.replace(" ", "")
    number = number.zfill(4)
    result = f"{number}-{rest}.cpp"
    return result

def main():
    parser = argparse.ArgumentParser(description='Transform Leetcode problem name to specific format.')
    parser.add_argument('name', type=str, help='The name of the Leetcode problem.')
    args = parser.parse_args()

    try:
        print(transform_name(args.name))
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()