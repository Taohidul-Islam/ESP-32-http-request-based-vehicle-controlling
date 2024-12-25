import requests
import keyboard  # For detecting key presses
import time  # For delays

# Replace with the IP address of your ESP32
ESP_IP = '192.168.123.132'

def control_pin(pin_number, action):
    """
    Sends a command to the ESP32 turn a specific pin ON or OFF.

    :param pin_number: The pin number (1-4)
    :param action: 'on' or 'off'
    """
    url = f"http://{ESP_IP}/{pin_number}{action}"
    try:
        response = requests.get(url)
        if response.status_code == 200:
            print(f"Pin {pin_number} is now {action.upper()}.")
        else:
            print(f"Failed to set Pin {pin_number}. Status code: {response.status_code}")
    except requests.RequestException as e:
        print(f"Error communicating with ESP32: {e}")

def main():
    print("Relay control program started.")
    print("Press the following keys to control the pins:")
    print("W: Pins 2 and 3 ON, release to turn OFF")
    print("S: Pins 1 and 4 ON, release to turn OFF")
    print("A: Pins 1 and 3 ON, release to turn OFF")
    print("D: Pins 2 and 4 ON, release to turn OFF")
    print("Press 'Esc' to exit the program.")

    # States to avoid sending redundant requests
    pin_states = {
        'w': False,
        's': False,
        'a': False,
        'd': False
    }

    try:
        while True:
            # W key logic (Pins 2 and 3)
            if keyboard.is_pressed('w') and not pin_states['w']:
                control_pin(2, 'on')
                control_pin(3, 'on')
                pin_states['w'] = True
            elif not keyboard.is_pressed('w') and pin_states['w']:
                control_pin(2, 'off')
                control_pin(3, 'off')
                pin_states['w'] = False

            # S key logic (Pins 1 and 4)
            if keyboard.is_pressed('s') and not pin_states['s']:
                control_pin(1, 'on')
                control_pin(4, 'on')
                pin_states['s'] = True
            elif not keyboard.is_pressed('s') and pin_states['s']:
                control_pin(1, 'off')
                control_pin(4, 'off')
                pin_states['s'] = False

            # A key logic (Pins 1 and 3)
            if keyboard.is_pressed('a') and not pin_states['a']:
                control_pin(1, 'on')
                control_pin(3, 'on')
                pin_states['a'] = True
            elif not keyboard.is_pressed('a') and pin_states['a']:
                control_pin(1, 'off')
                control_pin(3, 'off')
                pin_states['a'] = False

            # D key logic (Pins 2 and 4)
            if keyboard.is_pressed('d') and not pin_states['d']:
                control_pin(2, 'on')
                control_pin(4, 'on')
                pin_states['d'] = True
            elif not keyboard.is_pressed('d') and pin_states['d']:
                control_pin(2, 'off')
                control_pin(4, 'off')
                pin_states['d'] = False

            # Exit on 'Esc'
            if keyboard.is_pressed('esc'):
                print("Exiting program.")
                break

            time.sleep(0.1)  # Small delay to reduce CPU usage
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()
    
